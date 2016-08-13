// time: oc.cpp,2015-4-11
// Use cpp to scan a file and read output by line and token to string.
// Put the strings to a file named program.str
// Name: Hairong Wu
// Assignment: 104 assignment 1

#include <string>
using namespace std;

#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>
#include <assert.h>
#include <iostream>
#include <unordered_set>
#include <ctype.h>
#include "auxlib.h"
#include "stringset.h"
#include <unistd.h>

const string CPP = "/usr/bin/cpp";
const size_t LINESIZE = 1024;
char const delimiter[] = " \t\n";

void chomp (char* string, char delim) {
   size_t len = strlen (string);
   if (len == 0) return;
   char* nlpos = string + len - 1;
   if (*nlpos == delim) *nlpos = '\0';
}

// Run cpp on an input file.Read such file per line and token it. 
// Put each token into unordered set myset and dump to an output file.
void strtofile (FILE* pipe1, FILE* pipe2) {
    char buffer[LINESIZE];
    char *atoken = NULL;
    char *p = NULL; 
    
    //read per line and token to string. insert token to set
    while (fgets(buffer, LINESIZE, pipe1)!= NULL){
       p = buffer;
       chomp(buffer, '\n');
       while( (atoken = strtok_r(p, delimiter, &p))!=NULL  ){
           if(strcmp(atoken, "#")==0)
             break;
           intern_stringset (atoken);
        }
    }
    dump_stringset(pipe2);
    
}


void checkflag(int argc, char **argv){
    int c;
    string mystr = "";
    string str1  = "";
    for(int i=0; i<argc; i++ ){
      if(strcmp(argv[i], "-@")==0)
          mystr =  argv[i+1]; 
      if(strcmp(argv[i], "-D")==0)
           str1 = argv[i+1];
     }
    
    while ( ( c = getopt (argc, argv, "ly@D"))!= EOF )
        switch(c){
          case '@':
             set_debugflags(mystr.c_str()); 
             break;
           case 'D':
              str1 = CPP+ " "+"-D "+ str1;
              break;             
            case 'l':
              break;
            case 'y':
              break;             
            default: errprintf ("Bad option.");
              break;
         }
               
}




int main (int argc, char** argv) {
   //get inputfile name
   set_execname (argv[argc-1]);
   const string str = get_execname();
 
  //obtain outputfil name
   std::size_t found = str.rfind('.');
   if (found ==std::string::npos ) {
         errprintf(" %s has no suffix\n", str.c_str());
         return 1;
    }
   
    found = str.rfind(".oc");
    if (found ==std::string::npos ) {
          errprintf(" %s has wrong suffix!\n", str.c_str());
          return 1;
     }
   
   const string fileName = str.substr(0, str.length()-2)+"str";    
  
   //check option
   if (argc > 2){ checkflag(argc, argv);}
 
   //open input and output file
   char* inFileName  = argv[argc-1];
  
   const string command1 = CPP + " " + inFileName;
   //std::cout <<"command1= " <<command1.c_str() << std::endl; 
   FILE* pipeIn  = popen (command1.c_str(), "r");
   FILE* fileOut = fopen (fileName.c_str(), "w");
   if (pipeIn == NULL) {
         syserrprintf (command1.c_str());
       }
   
   if (fileOut == NULL) {
          syserrprintf (fileName.c_str());
       }
  
    //read per line and token the line.Put the output to a file.
    strtofile (pipeIn, fileOut);
    int pclose_rc = pclose (pipeIn);
    fclose(fileOut);
    eprint_status (command1.c_str(), pclose_rc);
  

    return get_exitstatus();
}

