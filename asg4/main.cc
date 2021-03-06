
#include <string>
#include <vector>
using namespace std;

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <set>

#include "astree.h"
#include "auxlib.h"
//#include "emit.h"
#include "lyutils.h"
#include "stringset.h"
#include "symboltab.h"




const string cpp_name = "/usr/bin/cpp"; 
const size_t LINESIZE = 1024;
char const delimiter[] = " \t\n";
string yyin_cpp_command;
FILE * fileOutTok;
FILE * fileOutAST;
FILE * fileOutSYM;
vector<symbol_table*> stack_sym;
extern set<string> type_Names;
// Open a pipe from the C preprocessor.
// Exit failure if can't.
// Assignes opened pipe to FILE* yyin.
void yyin_cpp_popen (const char* filename) {
   yyin_cpp_command = cpp_name;
   yyin_cpp_command += " ";
   yyin_cpp_command += filename;
   yyin = popen (yyin_cpp_command.c_str(), "r");
   if (yyin == NULL) {
      syserrprintf (yyin_cpp_command.c_str());
      exit (get_exitstatus());
   }
}

void yyin_cpp_pclose (void) {
   int pclose_rc = pclose (yyin);
   eprint_status (yyin_cpp_command.c_str(), pclose_rc);
   if (pclose_rc != 0) set_exitstatus (EXIT_FAILURE);
}

FILE*  f_open(const string filename){
   FILE* fileOut = fopen(filename.c_str(), "w");
   if (fileOut ==NULL){
      syserrprintf (filename.c_str());
      exit (get_exitstatus());
    }
   return fileOut;
}

//read file per line and token. dump the token
//into a file.
void strtofile ( FILE* pipe2) {
    char buffer[LINESIZE];
    char *atoken = NULL;
    char *p = NULL;

    //read per line and token to string. insert token to set
    while (fgets(buffer, LINESIZE, yyin)!= NULL){
      p = buffer;
      size_t len = strlen(p);
      if(*(p+len-1)=='\n'){*(p+len-1)='\0';} 
      while( (atoken = strtok_r(p, delimiter, &p))!=NULL  ){
           if(strcmp(atoken, "#")==0)
             break;
            
           intern_stringset (atoken);
        }
    }
    dump_stringset(pipe2);

}


bool want_echo () {
   return not (isatty (fileno (stdin)) and isatty (fileno (stdout)));
}


void scan_opts (int argc, char** argv) {
   int option;
   opterr = 0;
   yy_flex_debug = 0;
   yydebug = 0;
   for(;;) {
      option = getopt (argc, argv, "@:ely");
      if (option == EOF) break;
      switch (option) {
         case '@': set_debugflags (optarg);   break;
         case 'l': yy_flex_debug = 1;         break;
         case 'y': yydebug = 1;               break;
         default:  errprintf ("%:bad option (%c)\n", optopt); break;
      }
   }
   if (optind > argc) {
      errprintf ("Usage: %s [-ly] [filename]\n", get_execname());
      exit (get_exitstatus());
   }
   
   //obtain filename and dump token to xxx.str file
   const char* filename = optind == argc ? "-" : argv[optind];
   const string str = filename;
   const string fileSTRname = str.substr(0, str.length()-2)+"str";
   yyin_cpp_popen (filename);
   FILE *fileOut = f_open(fileSTRname); //fopen output file
   
   strtofile (fileOut); //put token to output file  
   fclose(fileOut);
   yyin_cpp_pclose();

   const string fileTOKname = str.substr(0, str.length()-2)+"tok";
   const string fileASTname = str.substr(0, str.length()-2)+"ast";
   const string fileSYMname = str.substr(0, str.length()-2)+"sym";
   
   fileOutTok = f_open(fileTOKname);
   fileOutAST = f_open(fileASTname);
   fileOutSYM = f_open(fileSYMname);
   yyin_cpp_popen (filename);
   DEBUGF ('m', "filename = %s, yyin = %p, fileno (yyin) = %d\n",
           filename, yyin, fileno (yyin));
   scanner_newfilename (filename);
}

int main (int argc, char** argv) {
  std::set<string> type_names; 
  int parsecode = 0;
   set_execname (argv[0]);
  vector<symbol_table*> symbol_stack;
   DEBUGSTMT ('m',
      for (int argi = 0; argi < argc; ++argi) {
         eprintf ("%s%c", argv[argi], argi < argc - 1 ? ' ' : '\n');
      }
   );
   scan_opts (argc, argv);

   parsecode = yyparse();
   if (parsecode) {
      errprintf ("%:parse failed (%d)\n", parsecode);
   }
   
   if (fileOutAST == NULL)
     printf("wroung fileOutAST pointer\n");
    //dump_astree(fileOutAST, yyparse_astree);
   //dump_astree_rec_c(stdout, yyparse_astree, 0);
   //dump_astree(stdout, yyparse_astree);
   //printf("tests size is %d\n", tests.size());
   symbol_table stack =new_stack();
   symbol_table topstack =new_stack();
   symbol_table* pstack= &stack;
   symbol_table* ptopstack=&topstack;
   stack_sym.push_back(pstack );
   stack_sym.push_back(ptopstack );
   traverTree(stack_sym[0], yyparse_astree, 0, 0);
   print_symtable(fileOutSYM,(stack_sym[0])); 
   //print_symtable(fileOutSYM,(stack_sym[1]));
   print_symtable(stdout,stack_sym[0]); 
   dump_astree(fileOutAST, yyparse_astree);
   dump_astree(stdout, yyparse_astree);
   printf("%d 166\n", stack_sym.size());
   scanner_setecho (want_echo());
   yyin_cpp_pclose();
   printf("type_Name size is %ld\n", type_Names.size());
   fclose(fileOutTok);
   fclose(fileOutAST);
   fclose(fileOutSYM);
   DEBUGSTMT ('s', dump_stringset (stderr); );
   yylex_destroy();
   return get_exitstatus();
}

RCSC("$Id: main.cc,v 1.4 2013-09-20 17:52:13-07 - - $")

