//astree.cc
#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "astree.h"
#include "stringset.h"
#include "lyutils.h"
#include "symboltab.h"

extern string typenames;

astree* new_astree (int symbol, int filenr, int linenr, int offset,
                    const char* lexinfo) {
   astree* tree = new astree();
   tree->structname= "";
   tree->symbol    = symbol;
   tree->filenr    = filenr;
   tree->linenr    = linenr;
   tree->offset    = offset;
   tree->blocknr   = 0;
   tree->attribute2 = "";
   tree->attribute2 = "";
   tree->attribute3 = "";
   tree->attribute4 = "";
   tree->attribute5 = "";
   tree->lexinfo = intern_stringset (lexinfo);
   DEBUGF ('f', "astree %p->{%d:%d.%d: %s: \"%s\"}\n",
           tree, tree->filenr, tree->linenr, tree->offset,
           get_yytname (tree->symbol), tree->lexinfo->c_str());
   return tree;
}

astree* new_ASTree(int symbol, astree* root){
    astree* tree = new_astree(symbol,root->filenr, root->linenr,root->offset,
        " " );
    return tree;
}

astree* adopt1 (astree* root, astree* child) {
   root->children.push_back (child);
   DEBUGF ('a', "%p (%s) adopting %p (%s)\n",
           root, root->lexinfo->c_str(),
           child, child->lexinfo->c_str());
   return root;
}

astree* adopt2 (astree* root, astree* left, astree* right) {
   adopt1 (root, left);
   adopt1 (root, right);
   return root;
}

astree* adopt3 (astree* root, astree* a1, astree* a2, astree* a3) {
   adopt1 (root, a1);
   adopt1 (root, a2);
   adopt1 (root, a3);
   return root;
}

astree* adopt4 (astree* root, astree* a1, astree* a2, astree* a3,
                astree* a4) {
   adopt1 (root, a1);
   adopt1 (root, a2);
   adopt1 (root, a3);
   adopt1 (root, a4);
   return root;
}

void swap (astree* root, int symbol){
     root->symbol = symbol;
}

/***************************************************
 * ************************************************/
astree* adopt1sym (astree* root, astree* child, int symbol) {
   //stackhead p= newstack();
   root = adopt1 (root, child);
   root->symbol = symbol;
   return root;
}


static void dump_node (FILE* outfile, astree* node) {
   fprintf (outfile, " %s \"%s\" (%ld.%ld.%ld) {%ld} %s %s %s %s %s",
             get_yytname (node->symbol),node->lexinfo->c_str(), 
            node->filenr, node->linenr, node->offset, node->blocknr,
            node->attribute1.c_str(), node->attribute2.c_str(),
            node->attribute3.c_str(), node->attribute4.c_str(),
            node->attribute5.c_str());
   bool need_space = false;
   for (size_t child = 0; child < node->children.size(); ++child) {
      if (need_space) fprintf (outfile, " ");
      need_space = true;
   }
    fprintf (outfile, " ");
}

static void dump_astree_rec (FILE* outfile, astree* root, int depth) {
   if (root == NULL) return;
   dump_node (outfile, root);
   
   fprintf (outfile, "\n");
   fprintf (outfile, "  ");
   for (size_t child = 0; child < root->children.size(); ++child) {
       for(int i=0; i< depth; i++ ) {fprintf (outfile, " | ");};
       dump_astree_rec (outfile, root->children[child], depth + 1);
   }
   
}
void dump_astree_rec_c (FILE* outfile, astree* root, int depth) {
   if (root == NULL) return;
   dump_node (outfile, root);
   
   fprintf (outfile, "\n"); 
   fprintf (outfile, "  ");
   for (size_t child = 0; child < root->children.size(); ++child) {
       for(int i=0; i< depth; i++ ) {fprintf (outfile, "  ");};
       dump_astree_rec (outfile, root->children[child], depth + 1);
   }
    
}


//check current node is "=" or not. yes return 1, no return 0.
bool check_lval(astree* root){
      bool p = strcmp(root->lexinfo->c_str(),"=");
      if (p==0){return 1;} 
      else     {return 0;}
}

//check current node is TOK_INT or not. yes return 1, no return 0.
bool check_INT(astree* root){
  bool q = strcmp(root->lexinfo->c_str(), "int");
  //bool p = strcmp(get_yytname(root->symbol), "INT");
  if(q==0){return 1;}
  else    {return 0;}
}





//**************************************************?????
//check current node is integer or signed integer
/*bool check_int(astree* root){
   bool result = false;
   bool integer = check_INTCON(root);
   bool signint = check_sign_int(root);
   if(signint ==1){
      result = true;
      
    }
    else if (integer ==1)
      result = true;
   return result;
}

//check current node is int or not. int=+/-integer
bool check_sign_int(astree* root, astree* parent){
  bool result = false;
  if(root->children.size()<1)  
     return result;
  bool padd   = strcmp(root->lexinfo->c_str(), "+");
  bool pmin   = strcmp(root->lexinfo->c_str(), "-");
  bool pchild = check_INTCON(root->children[0]);
  if((padd==0 && pchild==1)||(pmin==0 && pchild==1 )||pchild ==1)
     result = true;
  return result;
}*/

//check current root is '+'or '-'.one child is an int.
bool check_sign(astree* root){
   bool result = false;
   if (root->children.size()==1){
       bool padd   = strcmp(root->lexinfo->c_str(), "+");
       bool pmin   = strcmp(root->lexinfo->c_str(), "-");
       bool pint   = strcmp(get_yytname(root->children[0]->symbol), "INTCON");
       if((padd==0 && pint ==0)||(pmin==0 && pint ==0))
          result = true;
       
    }
   return result;
}

//check current node is an integer or not. integer is unsigned number.
bool check_INTCON(astree* root){
  bool result=false;
  if(root->children.size()==0){
     if(strcmp(get_yytname(root->symbol), "INTCON")==false)
         result = true;
   }
   return result;
}



//********************************************need to add more condition???
//check int_variable or not. int a = 3;int a = -3; a=3+3;
//root has exact two children. one is type int, one is int const.
bool check_int_variable(astree* root, symbol_table* ptable){
   bool result = false;
   bool peq = strcmp(root->lexinfo->c_str(), "=");
   if(peq==0 && root->children.size() == 2) {
     bool rightChild  = check_INTCON(root->children[1]);
     bool rightChild1 = check_int_vreg(root->children[1],ptable);
     bool leftChild   = check_INT(root->children[0]);
     string ident     = *(root->children[0]->lexinfo); 
     bool field = search_ident_insymbol_table(ident,ptable);
     //printf("%d %d %d 212\n", rightChild, rightChild1,leftChild);
     //for case int a =3||-3||3+3, 
     if((rightChild ==true||rightChild1==true) 
           && (leftChild==true)||field==true)  { 
         result = true;     
       }
     //********************************************need more condition
      //for case  a = 3|+3||3+3||b
    /* string leftC =*(root->children[0]->lexinfo);
     string rightC=*(root->children[1]->lexinfo);
     bool lintvari= test_ident_attri_insymbol_table(leftC, 
                "int",ptable);
     bool rintvari= test_ident_attri_insymbol_table(rightC, 
                "int",ptable);
     if((rintvari==true||rightChild ==true||rightChild1==true )
              && lintvari==true)
        result = true;*/
     //string ident = "a";
    // bool search = search_ident_insymbol_table(ident, ptable);
    // if(search==true){
      //  bool test = test_ident_attri_insymbol_table("a", "field", ptable);
      //  printf("%d %s %s \n", test, root->children[0]->lexinfo->c_str(),
      //                  root->children[1]->lexinfo->c_str());
   
  
       }
   return result;
}

//check char_variable. case like char a = 'x';
//root has exact two children. one is type char, one is char const.
bool check_char_variable(astree* root){
   bool result = false;
   bool peq = strcmp(root->lexinfo->c_str(), "=");
   if(peq==0 && root->children.size() == 2) {
     bool rightChild = check_CHARCON(root->children[1]);
     bool leftChild  = strcmp(root->children[0]->lexinfo->c_str(), "char");
     if(leftChild==0 && rightChild ==true)
         result = true;
      }
   return result;
}

//check bool_variable. case like bool a = false;
//root has exact two children. one is type bool, one is bool const.
bool check_bool_variable(astree* root){
   bool result = false;
   bool peq = strcmp(root->lexinfo->c_str(), "=");
   if(peq==0 && root->children.size() == 2) {
     bool rightChild = check_BOOLCON(root->children[1]);
     bool leftChild  = strcmp(root->children[0]->lexinfo->c_str(), "bool");
     if(leftChild==0 && rightChild ==true)
         result = true;
      }
   return result;
}
//check string_variable. string b = "xx"; 
bool check_string_variable(astree* root){
   bool result = false;
   bool peq = strcmp(root->lexinfo->c_str(), "=");
   if(peq==0 && root->children.size() == 2) {
     bool rightChild = check_STRINGCON(root->children[1]);
     bool leftChild  = strcmp(root->children[0]->lexinfo->c_str(), "string");
     if(leftChild==0 && rightChild ==true)
         result = true;
      }
   return result;
}





//check root is int_vret or not. Include case '+'int, '-'int
//int '+'/'-'/'*'/'/' int. Root is '+'||'-'||'*'||'/'.
//Children should be one or two int.
bool check_int_vreg(astree* root,symbol_table* ptable){
  bool result = false; 
  if((root->children.size()) < 1) {return false;}
  if (root->children.size() ==1){//case of unin operator
     string ident = *(root->children[0]->lexinfo);
     bool radd = strcmp(root->lexinfo->c_str(), "+");
     bool rmin = strcmp(root->lexinfo->c_str(), "-"); 
     bool r1   = check_INTCON(root->children[0]);
     bool r2   = test_ident_attri_insymbol_table(ident,"int",ptable);
     string leftc = *(root->children[0]->lexinfo);     
    // string rightc= *(root->children[1]->lexinfo);
     bool lintvar = test_ident_attri_insymbol_table(leftc, 
                                         "int", ptable);
    // bool rintvar = test_ident_attri_insymbol_table(rightc, 
      //                                   "int", ptable);

     if((radd ==0 || rmin==0 )
        &&(r1 ==true || r2==true||lintvar==true))
       result = true;
   }
   
   if((root->children.size()) == 2) {//case of binary operator
      bool padd = strcmp(root->lexinfo->c_str(), "+");
      bool pmin = strcmp(root->lexinfo->c_str(), "-");
      bool pmul = strcmp(root->lexinfo->c_str(), "*");
      bool pdiv = strcmp(root->lexinfo->c_str(), "/");
      bool pmod = strcmp(root->lexinfo->c_str(), "%");
     // printf("root %s + %d- %d *%d /%d \n", root->lexinfo->c_str(),
     // padd, pmin, pmul, pdiv);
      if(padd ==0 || pmin==0 ||pmul==0||pmod==0||pdiv==0){
          bool p1 =check_INTCON(root->children[0]);
          bool p2 =check_sign(root->children[0]);
          bool p3 =check_INTCON(root->children[1]);       
          bool p4 =check_sign(root->children[1]);
          string ident1=*(root->children[0]->lexinfo);
          string ident2=*(root->children[1]->lexinfo);
          bool p5 =test_ident_attri_insymbol_table(ident1,"int",ptable);
          bool p6 =test_ident_attri_insymbol_table(ident2,"int",ptable);
          if ((p1==1||p2==1||p5==1||p6==1)){//  &&(p3==1|| p4== 1||p6==1)) {
              result= true;// printf("!!!!!%d\n", result);
           }
      }
    }
     return result;
}

//check bool constant. they can true or false.
bool check_BOOLCON(astree* root){
   if(root->children.size()>0)
     return false;
   bool p1 = strcmp(root->lexinfo->c_str(), "false");
   bool p2 = strcmp(root->lexinfo->c_str(), "true");
   if(p1==0||p2==0)
     return true;
   else
     return false;
}

//check current node is "string" or not.
bool check_STRINGCON(astree* root){
   if(root->children.size()>0)
     return false;
   if( strcmp(get_yytname(root->symbol), "STRINGCON")==0)
        return true;
   else
        return false;
}

bool check_CHARCON(astree* root){
   bool result=false;
  if(root->children.size()>0){
     return false;
     }
   if( strcmp(get_yytname(root->symbol), "CHARCON")==0){
       result = true;
     }
      return result;
}

bool check_NULLCON(astree* root){
   if(root->children.size()>0)
     return false;
   if( strcmp(root->lexinfo->c_str(), "null")==0){
       //printf("%s %s 282\n", get_yytname(root->symbol),root->lexinfo->c_str()); 
       return true;
     }
   else
        return false;
 
}

//check a ident(current node of tree) is in symbol_table or not.
//need to tell not a base type, typeid
//need to add attribute into this node of the tree.  
bool check_ident_insymbol_table(astree* root,symbol_table* ptable){
  bool result = false;
  if (root->children.size()==0){
    string ident = *(root->lexinfo);
    if(search_ident_insymbol_table(ident,ptable)==1){ 
       result = true;
    //   printf("%s is in symbol_table\n", ident.c_str());
    }
  }
  return result;
}

//check '!'bool->bool vreg
bool check_bool_vreg_not(astree* root){
  bool result = false;
  if(root->children.size()== 1){
    bool p1 = strcmp(root->lexinfo->c_str(), "!"); 
    bool p2 = check_BOOLCON(root->children[0]);
    if(p1==0 && p2==1) { result = true;} 
   }
  return result;
}

//add int vreg attribute to astree node
bool check_ord_char(astree* root){
  bool result = false;
  if(root->children.size()== 1){
    bool p1 = strcmp(root->lexinfo->c_str(), "ord");
    bool p2 = check_CHARCON(root->children[0]);
    if (p1==0 && p2 ==1){result = true;} 
    }
  return result;
}
//check chr int type.will add char vreg to node 'chr'
bool check_chr_int(astree* root){
  bool result = false;
  //printf("%s 314\n", root->lexinfo->c_str());
  if(root->children.size()==1){
    bool pc = strcmp(root->lexinfo->c_str(), "chr");
    bool p1 = check_INTCON(root->children[0]);
    bool p2 = check_sign(root->children[0]);
    if (pc==0 && (p1==1||p2==1))
      result = true;
  }
  return result;
}


//bool check_int_array(){


//}


//check any==any or any!=any for null,string struct, string[]
//int[], char[], struct[], bool[] type
//now only check null string
bool check_any_eqne_any(astree* root){
  bool result = false;
  bool peq  = strcmp(get_yytname(root->symbol), "EQ");
  bool pne  = strcmp(get_yytname(root->symbol), "NE");
  if(root->children.size()==2 && (peq==0||pne==0)){
     bool pnull1   =check_NULLCON(root->children[0]);
     bool pnull2   =check_NULLCON(root->children[1]);
     bool pstring1 =check_STRINGCON(root->children[0]);
     bool pstring2 =check_STRINGCON(root->children[1]);
     if ((pnull1==1 && pnull2==1)||(pstring1==1 && pstring2==1)) 
        result = true;
  }
  return result;
}

//check primitive <  primitive.
//      primitive <= primitive
//      primitive >= primitive
//      primitive >  primitive  
//      primitive == primitive
//      primitive != primitive
//left match right, then push operon into table with property bool vreg
bool check_bool_LELTGEGT(astree* root){
   bool result = false; 
   bool plt    = strcmp(get_yytname(root->symbol), "LT");
   bool ple    = strcmp(get_yytname(root->symbol), "LE");
   bool pge    = strcmp(get_yytname(root->symbol), "GE");
   bool pgt    = strcmp(get_yytname(root->symbol), "GT");
   bool peq    = strcmp(get_yytname(root->symbol), "EQ");
   bool pne    = strcmp(get_yytname(root->symbol), "NE");
   if((plt==0||ple==0||pge==0||pgt==0||peq==0||pne==0)
     && root->children.size()== 2 ){
   bool lbool = check_BOOLCON(root->children[0]);
   bool rbool = check_BOOLCON(root->children[1]);
   if (lbool==1 && rbool ==1){
      result = true;
   //   printf("%s %s 334\n", root->children[0]->lexinfo->c_str(),
     //                     root->children[1]->lexinfo->c_str());
     }
    bool lchar = check_CHARCON(root->children[0]);
    bool rchar = check_CHARCON(root->children[1]);
    if (lchar==1 && rchar ==1){
      // printf("%s %s 340\n", root->children[0]->lexinfo->c_str(),
        //                  root->children[1]->lexinfo->c_str());
       result = true;
       }
    
    bool lsign = check_sign(root->children[0]);
    bool lint  = check_INTCON(root->children[0]);
    bool rsign = check_sign(root->children[1]);
    bool rint  = check_INTCON(root->children[1]);
   // printf("%s LT%d LE%d GE%d GT%d EQ%d NE%d\n", root->lexinfo->c_str(), 
     // plt, ple, pge, pgt, peq, pne);
   // printf("sign%d nosign%d sign%d nosign%d\n",lsign, lint, rsign, rint); 
   //  root->attribute1.c_str(), root->attribute2.c_str());
  if (( lsign==1 || lint ==1 )&&( rsign==1||rint ==1 )){
       result = true;
       //printf("%s %s 350\n", root->children[0]->lexinfo->c_str(),
         //                 root->children[1]->lexinfo->c_str());
     }
  }//if LT, children.size() ==2
   return result;    
}//func check_bool_LTLEGTGE

set<string> type_Names;
//search a string in type_Names. yes return 1, no return 0
bool find_typeid(string str){
  bool result = false;
  if(type_Names.find(str)!= type_Names.end() )
        result = true;   
  //printf("find string in type_Names %d \n", result);
  return result;
}

//determine a str is a type of int, bool, char, string, void, struct
bool check_basetype(string str){
  bool result  = false;
  bool p1 =strcmp(str.c_str(), "int");
  bool p2 =strcmp(str.c_str(), "bool");
  bool p3 =strcmp(str.c_str(), "char");
  bool p4 =strcmp(str.c_str(), "string");
  bool p5 =strcmp(str.c_str(), "void");
  bool p6 =strcmp(str.c_str(), "struct");
  if(p1==0||p2==0||p3==0||p4==0||p5==0||p6==0)
    result = true;
  return result;
}
//check a valid funcall or not
bool check_funcall(astree* root,symbol_table* ptable){
  bool result = false;
  bool p1 = strcmp(get_yytname(root->symbol),"CALL");
  if(p1==0){
    string funcname = *(root->children[0]->lexinfo);
    bool findfunc= search_ident_insymbol_table(funcname,ptable);
    if(findfunc==true){//need to check parameter type
      printf("find it!\n");
      result = true;
    }
  }
   return result;
}

// check   new typeid ()       if yes, add new node attribute vreg
// typeid go into type_Names(a globe set)
// need to search typeid is valid or not. 
bool check_new_typeid(astree* root){
  bool result= false;
  if(root->children.size()==1){
    bool pnew    = strcmp(root->lexinfo->c_str(), "new");
    const string* name = root->children[0]->lexinfo;
    bool pfind = find_typeid(*name);
    if(pnew==0 && pfind==1){
      result = true;
      printf("is new typeid %s %s %d?\n", root->lexinfo->c_str(), 
         root->children[0]->lexinfo->c_str(), result);
    }
  }
  return result;
}

//check new string(int) type. if yes, add node string attributes vreg
bool check_new_string_int(astree* root){
  bool result = false;
  if(root->children.size()==1){
     bool pnew = strcmp(get_yytname(root->symbol), "NEWSTRING");
     bool pint = check_INTCON(root->children[0]);
     if(pnew==0 && pint==1)
        result = true;  
   }
   return result;
}





//check new int[int]   
//      new char[int]
//      new bool[int]
//      new struct[int]  ******** not check yet
// base[] need to be added attribute vreg
bool check_new_base_int(astree* root){
   bool result = false;
 //  bool proot  = strcmp(root->lexinfo->c_str(), "="); //root is "="
   if(root->children.size()==2){
     bool parry  = strcmp(get_yytname(root->symbol), "NEWARRAY");
     bool pint =strcmp(root->children[0]->lexinfo->c_str(), "int");
     bool pchar=strcmp(root->children[0]->lexinfo->c_str(), "char");
     bool pbool=strcmp(root->children[0]->lexinfo->c_str(), "bool");
     //bool pstr =strcmp(root->children[0]->lexinfo->c_str(), "int");
     //bool pchar1 =strcmp(root->children[1]->lexinfo->c_str(), "char");
     //bool pbool1 =strcmp(root->children[1]->lexinfo->c_str(), "bool");
     //bool pintcon=strcmp(get_yytname(root->children[1]->children[0]->symbol),
     //"INTCON");
     bool pintcon = check_INTCON(root->children[1]);
     if(parry==0 && (pint==0||pchar==0||pbool==0) && pintcon==1 )
             result = true;
     }
    return result;
}


//check new string[int]. string will be added attribute vreg, vaddr lval
bool check_string_int(astree* root){
   bool result = false;
   if(root->children.size()==1){//case string[int]
     bool pstr    = strcmp(get_yytname(root->symbol), "NEWSTRING");
     bool pintcon = check_INTCON(root->children[0]);
     if(pstr==0 && pintcon==1)
        result = true;
     }
   return result;
}
/*
bool check_funcall(astree* root, symbol_table* ptable){
  bool result = false;
  if(root->children.size()==1){
    bool pstr=strcmp(get_yytname(root->symbol), "CALL");
    string ident=*(root->children->lexinfo);
    bool pfind=search_ident_insymbol_table(ident,ptable);
    if(pstr==0 && pfind ==true)
       result = true;
  return result;
}*/


//check case 3, +3, 3+3.All three case count int, return true 
bool check_int_intvreg(astree* root, symbol_table* ptable){
  bool result;
  if(root->children.size()==0){
     if(check_INTCON(root)==1)
        result = true;
    } 
  if(root->children.size()==1 || root->children.size()==2){
     if(check_int_vreg(root, ptable)==1)
        result = true;    
    }
   return result;
}

//process struct
void token_struct(symbol_table* ptable,astree* root,int block){
   bool pstruct = strcmp(root->lexinfo->c_str() , "struct");
   if(root->children.size()>0 && pstruct==0){
     adding_struct_tosymbol_tab(block,ptable,root);
     adding_struct_toAst( root);
  }
}




//process function
void token_function(symbol_table* ptable, astree* root,
                      int block){
   bool pstruct = strcmp(get_yytname(root->symbol) , "FUNCTION");
   if(root->children.size()>0 && pstruct==0){
     
     symbol_table astack=new_stack();
     //adding_func_tosymbol_tab(&astack, root,block);
     adding_func_tosymbol_tab(ptable,root,block);
     adding_func_toAst(ptable, root,block);
    // adding_block_toAst(ptable,  root,block);
     
   }
}


void token_block(symbol_table* ptable, astree* root,
                      int block){
   bool pblock = strcmp(get_yytname(root->symbol) , "BLOCK");
   if(root->children.size()>0 && pblock==0){
     symbol_table astack=new_stack();
     symbol_table topstack =new_stack();
     symbol_table* anewstack=&astack;
     symbol_table* ptopstack=&topstack;
     stack_sym.pop_back();
     stack_sym.push_back(anewstack); 
     stack_sym.push_back(ptopstack );
     adding_block_tosymbol_tab(stack_sym[block+1], root,block);
     adding_block_toAst(stack_sym[block+1],  root,block);
   }


}

//push prototype name into symbol_table
void token_prototype(symbol_table* ptable, astree* root,
                      int block){
   if(strcmp(get_yytname(root->symbol), "PROTOTYPE") !=0 )
      return;
   string type= *(root->children[0]->lexinfo);
   string name= *(root->children[0]->children[0]->lexinfo);
   int filenr =root->children[0]->children[0]->filenr;
   int linenr =root->children[0]->children[0]->linenr;
   int offset =root->children[0]->children[0]->offset;
   symbolPtr ptr = newSymbol(filenr,linenr,offset);

   ptr->blocknr=block;
   int index1 = string_tobit(type);
   //printf("%s %d 699\n", type.c_str(), index1);
   //ptr->attributes.set(index1, 1);
   (*ptable).insert({name, ptr});
   //set_bitset_attribute(name, index1, ptable);
   adding_prototype_toAst(ptable, root, block);
   
   return;

}



//obtain key string from root and set attribute on.Receive int bitsetIndex.
void adding_sym_tab_attri(symbol_table* ptable,astree* root, 
                           int bitsetIndex){
     string key = *(root->lexinfo);
     set_bitset_attribute(key, bitsetIndex, ptable);
}

/*
//adding current node to symbol_table. adding int vreg attribute to it.
//current node can be '+'||'-'||'*'||'/'||'%'(case 3+3, or +3)
void adding_int_vreg_tosymbol_tab(symbol_table* ptable,astree* root){
    int bitsetIndex1 = ATTR_int;
    int bitsetIndex2 = ATTR_vreg;
    adding_symtable(*(root->lexinfo), root->filenr, root->linenr,
                        root->offset, ptable);
         
    adding_sym_tab_attri(ptable,root, bitsetIndex1);
    adding_sym_tab_attri(ptable,root, bitsetIndex2);
    int num = get_bitset_count(*(root->lexinfo),ptable);
    string attribute1 = bit_tostring(bitsetIndex1);
    string attribute2 = bit_tostring(bitsetIndex2);
  //  printf("bit count is %d %s %s %s %s 248\n",num, root->lexinfo->c_str(),
   // get_yytname(root->symbol), attribute1.c_str(), attribute2.c_str());

}
}*/

void adding_one_attribute_toAst(int block,string str, astree* root){
     root->attribute1 = str;
     //if(root->blocknr==0)
       // root->blocknr = block;
    // printf("386 %s %ld %s\n", root->lexinfo->c_str(), root->filenr,
    // root->attribute.c_str());

}


void adding_two_attribute_toAst(int block, string str1,
                            string str2, astree* root){
     root->attribute1 = str1;
     root->attribute2 = str2;
    // if(root->blocknr==0)
      //  root->blocknr = block;
     
    // printf("386 %s %ld  %s %s\n", root->lexinfo->c_str(), root->filenr,
    // root->attribute1.c_str(), root->attribute2.c_str());

}

void adding_three_attribute_toAst(int block, string str1,string str2, 
                string str3, astree* root){
    root->attribute1 = str1;
    root->attribute2 = str2;
    root->attribute3 = str3;
   // if(root->blocknr==-1)
     //   root->blocknr = block;
    
   // printf("386 %s %ld  %s %s %s\n", root->lexinfo->c_str(), root->filenr,
 // root->attribute1.c_str(),root->attribute2.c_str(),root->attribute3.c_str());

}


//adding root->children[0]->children[0] to symbol_table. adding attribute
//attr, variable and lval to it.(case int a = 3;)
void adding_variable_tosymbol_tab(string attr, 
           symbol_table* ptable, astree* root, int block){
    int bitsetIndex1 = string_tobit(attr);
    int bitsetIndex2 = ATTR_variable;
    int bitsetIndex3 = ATTR_lval;
    astree* grandson = root->children[0]->children[0];
    adding_symtable(*(grandson->lexinfo), grandson->filenr, grandson->linenr,
                        grandson->offset, block, ptable);
    adding_sym_tab_attri(ptable,grandson, bitsetIndex1);
    adding_sym_tab_attri(ptable,grandson, bitsetIndex2);
    adding_sym_tab_attri(ptable,grandson, bitsetIndex3);
    //int num1 = get_bitset_count(*(grandson->lexinfo),ptable);
   // string at1 = bit_tostring(bitsetIndex1);
   // string at2 = bit_tostring(bitsetIndex2);
   // string at3 = bit_tostring(bitsetIndex3);
    //printf("%d %s %s %s %s %s 250\n",num1, grandson->lexinfo->c_str(), 
    //get_yytname(grandson->symbol),at1.c_str(),at2.c_str(),at3.c_str());
}


void adding_struct_tosymbol_tab(int block, symbol_table* ptable,
                                          astree* root){
   bool pstruct = strcmp(root->lexinfo->c_str(), "struct");
   int childnum = root->children.size();
   if (pstruct == 0 && childnum >=1){
    string structid =*(root->children[0]->lexinfo);
    auto find = type_Names.find(structid);
    if (find != type_Names.end())
        type_Names.insert(structid);
    //case childnum ==1, empty struct only one child
    int filenr = root->children[0]->filenr;
    int linenr = root->children[0]->linenr;
    int offset = root->children[0]->offset;
    int bitsetIndex = ATTR_struct;
    adding_symtable(structid, filenr,linenr, 
                       offset, block, ptable); 
      // printf("index %d ", bitsetIndex);
      
    set_bitset_attribute(structid, bitsetIndex, ptable);
    //print_bitset(structid, ptable);
    //need to add field into symbol_table fields
    if(childnum >1) {
      //create a symbol_table pointer to field 
      symbolPtr onesym = newSymbol(0,0,0);
      symbol_table atab;
      (atab).insert({ "", onesym});
      int bitsetIndexchild = ATTR_field; 
      auto search = (*ptable).find(structid);
      if (search != (*ptable).end()){
         search->second->blocknr=0;
         search->second->fields=&atab;
         if (search->second->fields !=NULL){//add child to field         
            for(int i= 1; i<childnum;i++){
            
             int cfilenr = root->children[i]->children[0]->filenr;
             int clinenr = root->children[i]->children[0]->linenr;
             int coffset = root->children[i]->children[0]->offset;
      // symbolPtr onesym = newSymbol(0,0,0);
            string fieldkey = *(root->children[i]->children[0]->lexinfo);
            string attribute =*(root->children[i]->lexinfo);
            int bitattribute = string_tobit(attribute);  
      //symbol_table* field = (symbol_table*)malloc(sizeof(symbol_table));
         //printf(" %d 636 \n",(atab).size());
           //  int indextest = string_tobit("int");
         // printf("test int index is %d\n", indextest);
       // auto search = (*ptable).find(structid);
             adding_symtable(fieldkey, cfilenr, clinenr,coffset, 
                              block, search->second->fields);
              set_bitset_attribute(fieldkey, bitsetIndexchild, 
                                  search->second->fields);
              set_bitset_attribute(fieldkey, bitattribute,
                                  search->second->fields);
            //  printf(" %d 641\n",(*(search->second->fields)).size());  
            //  print_symtable(stdout, (*(search->second->fields))); 
             }  
       }
     //  print_symtable(stdout, ((search->second->fields))); 
      }   
   }
  }
}

// adding func name into symbol_table.
//return true if add success. false if not valid func and don't push.  
bool adding_func_name_tosym(symbol_table* ptable, astree* root,
                                int block){
   string type    = *(root->children[0]->lexinfo);
   bool pbase   =check_basetype(type);
   bool ptypeid =find_typeid(type);
   if(pbase==0 && ptypeid==0){//not a base type nor a struct type
      printf("not a valid function type\n"); 
      return false;
    }
   //int numchild= root->children.size();
   //if (numchild==1)
    string funcname=*(root->children[0]->children[0]->lexinfo);
   // auto search = (*ptable).find(funcname);
   // if (search != (*ptable).end()){
   //    printf("function already in symbol_table!\n");
   //    return false;
   //   }
    int filenr =root->children[0]->children[0]->filenr;
    int linenr =root->children[0]->children[0]->linenr;
    int offset =root->children[0]->children[0]->offset;
    symbolPtr ptr = newSymbol(filenr,linenr,offset);
    ptr->blocknr=block;
    bool pfunc = strcmp(get_yytname(root->symbol), "FUNCTION");
    bool pproto= strcmp(get_yytname(root->symbol), "PROTOTYPE");
    int index1 = string_tobit(type);//if struct, need to know name
    int index2 = ATTR_function;
    ptr->attributes.set(index1, 1);
    ptr->attributes.set(index2, 1);
    (*ptable).insert({funcname, ptr});
    return true;
}

//
void adding_func_para_tosym(symbol_table* ptable, astree* root,
                                int block){
    int numpara= root->children[1]->children.size();
    //printf("num of para is %d \n", numpara);
    if(numpara==0)
        return;
    string funcname = *(root->children[0]->children[0]->lexinfo);//key
    auto search = (*ptable).find(funcname);
    if (search != (*ptable).end()) 
      search->second->parameters= new vector<symbol*>[10];
    astree* parp[numpara];
    for(int i=0; i<numpara; i++){
       //string funcname = *(root->children[0]->children[0]->lexinfo);//key
       //astree* parp[numpara];
       parp[i] =root->children[1]->children[i]; 
      // parp[1] =root->children[1]->children[1]; 
       string type = *(parp[i]->lexinfo);
      // const string* declid= (parp[i]->children[0]->lexinfo);
       int filenr = parp[i]->children[0]->filenr;
       int linenr = parp[i]->children[0]->linenr;
       int offset = parp[i]->children[0]->offset;
       symbol* ptr = newSymbol(filenr,linenr,offset);
       ptr->blocknr=block;
       //ptr->name = new char[20*sizeof(char)];
       //string temp = *(parp[i]->children[0]->lexinfo);
       
       ptr->name = parp[i]->children[0]->lexinfo;
       string temp = *(ptr->name);
       //*(ptr->name) = temp;
       //printf("%s %s 888\n",ptr->name,temp.c_str());
       //printf("%p %s 888\n",ptr->name,temp.c_str());
       int index1 = string_tobit(type);
       int index2 = ATTR_variable;
       int index3 = ATTR_lval;
       int index4 = ATTR_param;   
       ptr->attributes.set(index1, 1);
       ptr->attributes.set(index2, 1);
       ptr->attributes.set(index3, 1);
       ptr->attributes.set(index4, 1);
       auto find1 = (*ptable).find(funcname);
       if (find1 != (*ptable).end()){
        //vector<symbol*> *p= new vector<symbol*>[10]; 
        //search->second->parameters= new vector<symbol*>[10];
         find1->second->parameters->push_back(ptr);
       // printf("%s %d 836\n",ptr->name,
        //tring temp = *(parp[i]->children[0]->lexinfo);
      //  ptr->name = new string(temp); 
        //             search->second->filenr); 
       }
     }
     return;
}   



void adding_func_tosymbol_tab(symbol_table* ptable, astree* root,
                                int block){
   bool pstruct = strcmp(get_yytname(root->symbol) , "FUNCTION");
   if(root->children.size() >= 3 || pstruct==0){
      adding_func_name_tosym(ptable,root,block);
      adding_func_para_tosym(ptable,root,block);
      //adding_block_tosym(ptable, root, block);

   }
      /*
   string type    = *(root->children[0]->lexinfo);
   bool pbase   =check_basetype(type); 
   bool ptypeid =find_typeid(type);
   if(pbase==0 && ptypeid==0)//not a base type nor a struct type
      return;
   int numchild= root->children.size();
   if (numchild==1){
   //may need to handle func with identity name
     string funcname=*(root->children[0]->children[0]->lexinfo);
     auto search = (*ptable).find(funcname);
     if (search != (*ptable).end())
     printf("function already in symbol_table!\n"); 
   //push func name into symbol_table 
     int filenr =root->children[0]->children[0]->filenr;
     int linenr =root->children[0]->children[0]->linenr;
     int offset =root->children[0]->children[0]->offset;
   
   
     symbolPtr ptr = newSymbol(filenr,linenr,offset);
     ptr->blocknr=block;
     int index1 = string_tobit(type);//if struct, need to know name
     int index2 = ATTR_function;
     ptr->attributes.set(index1, 1);
     ptr->attributes.set(index2, 1);
     (*ptable).insert({funcname, ptr});
  }
   //need to process parameter

   int numchild= root->children.size();
   string attric= root->
   int filenrc=root->children[1]->children[0]->filenr;
   int linenrc=root->children[1]->children[0]->linenr;
   int offsetc=root->children[1]->children[0]->offset;
   symbolPtr para= newSymbol(filenrc,linenrc,offsetc);
   para->blocknr=block;
   
   */
 }

//need to add more type check into block.
void  adding_block_tosymbol_tab(symbol_table* ptable, astree* root,
                               int block){
    int numchild = root->children.size();
    //printf("%s %d958\n", root->lexinfo->c_str(), root->children.size());
   for(int i =0; i<numchild;i++){
     bool p = check_int_variable(root->children[i], ptable);
     if(p==true){ 
       astree* temp=root->children[i]->children[0]->children[0];
       adding_symtable(*(temp->lexinfo),temp->filenr, temp->linenr,
                        temp->offset, block+1, ptable );
        int index1 = string_tobit("int");
        int index2 = string_tobit("variable");
        int index3 = string_tobit("lval");      
        set_bitset_attribute(*(temp->lexinfo),index1, ptable);
        set_bitset_attribute(*(temp->lexinfo),index2, ptable);
        set_bitset_attribute(*(temp->lexinfo),index3, ptable);
       // printf("%s %d %d 960\n",
        //  temp->lexinfo->c_str(), temp->filenr, temp->linenr);
       print_symtable(stdout, ptable); 
     }
   }
   // printf("here is block\n");
   // print_symtable(stdout, ptable);
}

//ident is in symbol_table. find its attribute in symbol_table and 
//add them to astree node.limited to 3 attributes.
void adding_sym_ident_attri_toAst(int block, astree* root,
                                   symbol_table* ptable){
   bool pident = strcmp(get_yytname(root->symbol), "IDENT");
   string attri[10];
   if(root->children.size()> 0 || pident!= 0)
      return;
   string ident = *(root->lexinfo);
   auto search = (*ptable).find(ident);
   if (search == (*ptable).end())
      return;
   //printf("");
   attr_bitset mybit = search->second->attributes;
   for(int bitindex=0, j=0; bitindex<ATTR_bitset_size; 
                                              bitindex++){
     if(mybit.test(bitindex)==true) {
        attri[j] = bit_tostring(bitindex);
        //printf("%s attribute is %s\n",ident.c_str(), attri[j].c_str());  
        //adding_one_attribute_toAst(ident,root);
        j++;
       }
     if(j==1)
         adding_one_attribute_toAst(block,attri[0],root);
     if(j==2)
        adding_two_attribute_toAst(block,attri[0],attri[1],root);
     if(j==3)
        adding_three_attribute_toAst(block, attri[0],attri[1],
                                       attri[2],root);
   }
}
//adding struct information to astree node
void adding_struct_toAst(astree* root){
   bool pstruct = strcmp(root->lexinfo->c_str(), "struct");
   int childnum = root->children.size();
   if (pstruct != 0)
     return;
   if( childnum >=1){//empty struct only one child
      //printf("test!");
   
     root->blocknr=0;
     root->attribute1 = "struct";
     string structid =*(root->children[0]->lexinfo);
     root->attribute2 = structid;
     root->children[0]->blocknr =0; 
     root->children[0]->attribute1 = "struct";
     root->children[0]->attribute2 = structid;
     
     if(childnum >1){//struct has field, update field
        for(int i = 1; i<childnum; i++){
         string attribute = *(root->children[i]->lexinfo);
        // root->children[i]->attribute1 = "struct";
        // root->children[i]->attribute2 = structid;
         root->children[i]->children[0]->attribute1 = "field";
         root->children[i]->children[0]->attribute2 = structid;
         root->children[i]->children[0]->attribute3 = attribute;
          } 
        }
   }
}

void adding_func_toAst(symbol_table* ptable, astree* root,
                      int block){
   bool pfunc = strcmp(get_yytname(root->symbol), "FUNCTION");
   int childnum = root->children.size();
   if (pfunc != 0)
     return;
   if( childnum !=3)
     return;
      //root token function
   string funcname = *(root->children[0]->children[0]->lexinfo);
   string functype = *(root->children[0]->lexinfo);
   root->blocknr=block;
  // printf("block nr is %d %s\n", block, get_yytname(root->symbol));
   root->attribute1=functype;
   root->attribute2="function";
   //func name   
   root->children[0]->children[0]->blocknr = block+1;
   root->children[0]->children[0]->attribute1=functype;
   root->children[0]->children[0]->attribute2="function";
   //parameter
   int paranum = root->children[1]->children.size();
      //printf("num of para 998 is %d\n", paranum);
   if(paranum >0){
     astree* para[paranum];
     for(int i=0;i<paranum; i++){
       para[i]   =root->children[1]->children[i];
     //astree* para2   =root->children[1]->children[1];
       string paratype = *(para[i]->lexinfo);
       //string paratype2 = *(para2->lexinfo);
       string paraname = *(para[i]->children[0]->lexinfo); 
       if(search_ident_insymbol_table(paraname, ptable)==true){
          if(test_ident_attri_insymbol_table(paraname,"variable",
                                              ptable)==true){
         para[i]->children[0]->attribute1= paratype;       
         para[i]->children[0]->attribute2="variable";
         para[i]->children[0]->attribute3="lval";
         para[i]->children[0]->attribute4="param";
         para[i]->children[0]->blocknr = block+1; 
         //printf("block nr is %d %s\n", block+1, paraname.c_str()); 
      }
       if(test_ident_attri_insymbol_table(paraname,"const",
                                    ptable)==true){
         para[i]->children[0]->attribute1= paratype;     
         para[i]->children[0]->attribute2="const";
         para[i]->children[0]->attribute4="param";
         para[i]->children[0]->blocknr = block+1; 
       } 
     }//if find
     para[i]->children[0]->attribute1= paratype; 
     para[i]->children[0]->attribute4="param"; 
     para[i]->children[0]->blocknr = block+1;
     }
  }
}

void adding_block_toAst(symbol_table* ptable, astree* root,
                      int block){
   
   bool pblock = strcmp(get_yytname(root->symbol), "BLOCK");
   int num = root->children.size();
  // printf("hello %d %s\n", pblock, get_yytname(root->symbol));
   if (pblock != 0)
     return;
   //printf("test!\n");
   if( num ==0)
     return;
   astree* blockchild[num];
   for(int i=0; i<num;i++){
     blockchild[i]= root->children[i];
     if(check_int_variable(blockchild[i], ptable)==true
      ||check_char_variable(blockchild[i])==true
      ||check_bool_variable(blockchild[i])==true
      ||check_string_variable(blockchild[i])==true
      ||check_BOOLCON(blockchild[i])==true
      ||check_STRINGCON(blockchild[i])==true
      ||check_CHARCON(blockchild[i])==true
      ||check_NULLCON(blockchild[i])==true
      ||check_ord_char(blockchild[i])==true
      ||check_chr_int(blockchild[i])==true){  
       blockchild[i]->children[0]->children[0]->blocknr=block+1;
     }
      

  }
}

void  adding_prototype_toAst(symbol_table* ptable, astree* root,
                               int block){
   bool proto = strcmp(get_yytname(root->symbol), "PROTOTYPE");
   int num = root->children.size();
   if(proto != 0)
      return;
   if(num!=2)
      return;
    root->attribute1 = "prototype";
    if(strcmp(get_yytname(root->children[0]->symbol), "ARRAY")==0){
       string typenames = *(root->children[0]->children[0]->lexinfo);
       root->children[0]->children[1]->attribute1=typenames;
       root->children[0]->children[1]->attribute2="array";
       root->children[0]->children[1]->attribute3="prototype";
    }    
    string type = *(root->children[0]->lexinfo);
    root->children[0]->children[0]->attribute1= type;
    root->children[0]->children[0]->attribute2= "prototype"; 
    
    int numpara= root->children[1]->children.size();
    if (numpara==0)
       return;
    for(int i=0;i<numpara; i++){    
      astree* para=root->children[1]->children[i];
      if(strcmp(get_yytname(para->symbol), "ARRAy")==0){
         string parat= *(para->children[0]->lexinfo);
         para->children[1]->attribute1=parat;
         para->children[1]->attribute2="array";
         para->children[1]->attribute3="param";
         para->children[1]->attribute4="prototype";
      }
      string paratype = *(para->lexinfo);
      para->children[0]->attribute1=paratype;
      para->children[0]->attribute2="param";
      para->children[0]->attribute3="prototype";
 
  }//for loop
}

/*
//adding <,<=,>,>=,==,!=,'!' into astree node with property bool vreg
void adding_bool_vreg_tosymbol_tab(symbol_table* ptable, astree* root){
   int bitsetIndex1 = ATTR_bool;
   int bitsetIndex2 = ATTR_vreg;
   adding_symtable(*(root->lexinfo), root->filenr, root->linenr,
                        root->offset, ptable);
   adding_sym_tab_attri(ptable,root, bitsetIndex1);
   adding_sym_tab_attri(ptable,root, bitsetIndex2);
   int num = get_bitset_count(*(root->lexinfo),ptable);
   string attribute1 = bit_tostring(bitsetIndex1);
   string attribute2 = bit_tostring(bitsetIndex2);
   //printf("table size is %d \n", (*ptable).size());
   //printf("bit count is %d %s %s %s %s 248\n",num, root->lexinfo->c_str(),
   //get_yytname(root->symbol), attribute1.c_str(), attribute2.c_str());
  
}*/

//void travel_preorder(int block, symbol_table* ptable,
//                       astree* root, int depth){
      //if (check_INTCON(root)==1)
  //         if( check_new_typeid(root)==1)//typeid add attribute vreg
   //           adding_one_attribute_toAst(block, "vreg",root->children[0]);
   // for (size_t child =0; child<root->children.size(); ++child )
  //          travel_preorder(block, ptable, root->children[child],  depth+1);
//}



//set<string> typenames;
//typenames.insert("q");

//set<string> type_Names;

//traverse tree with postorder
void traverTree(symbol_table* ptable, astree* root, 
                 int depth, int block){
   
         
         token_function(ptable,root, block);
         token_struct(ptable,root,block);
         token_block(ptable,root, block); 
         token_prototype(ptable,root,block);
        // adding_struct_tosymbol_tab(ptable,root);  
        // adding_struct_toAst( root);
       //  travel_preorder(block,ptable, root,  depth);
         //adding_symtable(*(root->lexinfo), root->filenr, root->linenr,
                       // root->offset, ptable);                     
        //string temp = root->lexinfo->c_str();
         
        //adding_symtable(*(root->lexinfo), root->filenr, root->linenr,
          //              root->offset, ptable);
       // for(size_t child =0; child<root->children.size(); ++child )
         //   traverTree(&anewTab, root->children[child],  0);
     // } 
      for (size_t child =0; child<root->children.size(); ++child )
            traverTree(ptable, root->children[child],  depth+1,block);    
         // printf(" token is %s \n", get_yytname (root->symbol));
          //insert int char string bool void into type_Names set
          if(strcmp(get_yytname (root->symbol), "TRUE")==0 ||
            strcmp(get_yytname (root->symbol), "FALSE")==0) {
            type_Names.insert("bool");
            type_Names.insert("foo");
            type_Names.insert("bar");
            type_Names.insert("classroom");
            //printf("%ld", type_Names.size());
            if(type_Names.find("bar")!= type_Names.end())
                     printf("yes find name in type_Name");
            adding_two_attribute_toAst(block,"bool","const", root);
             }
          if(strcmp(get_yytname (root->symbol), "CHARCON")==0 ) {
             type_Names.insert("char");
             adding_two_attribute_toAst(block,"char","const", root);
            }
          if(strcmp(get_yytname (root->symbol), "INTCON")==0 ) {
             type_Names.insert("int");
             adding_two_attribute_toAst(block,"int","const", root);
            }
          if(strcmp(get_yytname (root->symbol), "STRINGCON")==0 ) {
             type_Names.insert("string");
             adding_two_attribute_toAst(block,"string","const", root);
            }
          if(strcmp(get_yytname (root->symbol), "VOID")==0 ) {
             type_Names.insert("void");
            }
          if(check_NULLCON( root)==1)
             adding_two_attribute_toAst(block,"null","const", root);
          if (check_bool_vreg_not( root)==1)
             adding_two_attribute_toAst(block,"bool","vreg", root);
          if (check_ord_char(root)==1)
             adding_two_attribute_toAst(block,"int","vreg", root);
          if (check_bool_LELTGEGT(root)==1)
             adding_two_attribute_toAst(block,"bool","vreg", root);
          if(check_int_vreg(root,ptable)==1)
             adding_two_attribute_toAst(block,"int","vreg", root);
          if(check_chr_int( root)==1)
             adding_two_attribute_toAst(block,"char","vreg", root);
          if(strcmp(root->lexinfo->c_str(), "int")==0)
             adding_one_attribute_toAst(block,"int", root);
          if(strcmp(root->lexinfo->c_str(), "bool")==0)       
             adding_one_attribute_toAst(block,"bool", root);
          if(strcmp(root->lexinfo->c_str(), "string")==0)       
             adding_one_attribute_toAst(block,"string", root); 
          if(strcmp(root->lexinfo->c_str(), "void")==0)       
             adding_one_attribute_toAst(block,"void", root);
          if(strcmp(root->lexinfo->c_str(), "char")==0)       
             adding_one_attribute_toAst(block,"char", root);          
          if( check_new_string_int(root)==1)
              adding_one_attribute_toAst(block,"vreg",root);
          if( check_new_base_int(root)==1){
             adding_one_attribute_toAst(block,"vreg", root);
             adding_two_attribute_toAst(block,"vaddr","lval", 
                                         root->children[0]);
              }   
          if (check_int_variable(root, ptable)==true){
              
                 //root->children[0]->children[0]->blocknr==0){ 

             adding_three_attribute_toAst(block,"int","variable",
               "lval",root->children[0]->children[0]);
             if(root->children[0]->children[0]->blocknr==0){
                 adding_variable_tosymbol_tab("int",ptable,
                                      root, block);      
                }
             }
          if(check_char_variable(root)==1){
             adding_three_attribute_toAst(block,"char","variable",
             "lval", root->children[0]->children[0]);
             if(root->children[0]->children[0]->blocknr==0){
                adding_variable_tosymbol_tab("char",ptable,
                                      root, block);
              }
           }
          if(check_bool_variable(root)==true){ 
             adding_three_attribute_toAst(block,"bool",
                "variable","lval",root->children[0]->children[0]);
             if(root->children[0]->children[0]->blocknr==0){
             adding_variable_tosymbol_tab("bool",ptable,root,block); 
              }
             }
          if(check_string_variable(root)==true){
            // root->children[0]->children[0]->blocknr==0){
             adding_three_attribute_toAst(block,"string",
            "variable","lval",root->children[0]->children[0]);
             if(root->children[0]->children[0]->blocknr==0){
               adding_variable_tosymbol_tab("string",
                                    ptable,root, block);
               }
            }
          if(check_ident_insymbol_table(root,ptable)==true){
             adding_sym_ident_attri_toAst(block,root,ptable);            
             
              }
           // if(check_string_int(root)==0)
           //  adding_three_attribute_toAst("char","vaddr","lval", root);
}


//bool type_check(astree* root){
  


//}


void dump_astree (FILE* outfile, astree* root) {
   dump_astree_rec (outfile, root, 0);
   fflush (NULL);
}

void yyprint (FILE* outfile, unsigned short toknum, astree* yyvaluep) {
   DEBUGF ('f', "toknum = %d, yyvaluep = %p\n", toknum, yyvaluep);
   if (is_defined_token (toknum)) {
      dump_node (outfile, yyvaluep);
   }else {
      fprintf (outfile, "%s(%d)\n", get_yytname (toknum), toknum);
   }
   fflush (NULL);
}


void free_ast (astree* root) {
   while (not root->children.empty()) {
      astree* child = root->children.back();
      root->children.pop_back();
      free_ast (child);
   }
   DEBUGF ('f', "free [%X]-> %d:%d.%d: %s: \"%s\")\n",
           (uintptr_t) root, root->filenr, root->linenr, root->offset,
           get_yytname (root->symbol), root->lexinfo->c_str());
   delete root;
}

void free_ast2 (astree* tree1, astree* tree2) {
   free_ast (tree1);
   free_ast (tree2);
}

void free_ast3 (astree* tree1, astree* tree2, astree* tree3) {
   free_ast (tree1);
   free_ast (tree2);
   free_ast (tree3);
}
RCSC("$Id: astree.cc,v 1.14 2013-10-10 18:48:18-07 - - $")

