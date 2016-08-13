// $Id: symbol-tab.cc 

#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
#include "astree.h"
#include "stringset.h"
#include "lyutils.h"

#include "symboltab.h"



//receive a string as a key and integer as index of bitset.
//Set this bit on as its attribute. defined by enum   
void set_bitset_attribute(string str, int index, symbol_table* atab){
   auto search = (*atab).find(str);
   if (search != (*atab).end()){
     //printf("good search!"); 
     search->second->attributes.set(index, 1);
   }
  return;
}

//given string key, print out the bitset attribute in the symbol_table
void print_bitset(string str, symbol_table* atab){
  auto search = (*atab).find(str);
   if (search != (*atab).end()){
    string temp = search->first;  
    attr_bitset mybit = search->second->attributes;
    string mybits=
mybit.to_string<char,std::string::traits_type,std::string::allocator_type>();
    printf("find %s %s ! \n", temp.c_str(), mybits.c_str());
     
   }
  return;
}

//search a ident in the symbol_table or not. yes return true. no false
bool search_ident_insymbol_table(string ident, symbol_table* ptable){
   bool result = false;
   auto search = (*ptable).find(ident);
   if (search != (*ptable).end())
     result = true;
   return result;
}

//change string attri to int bit index. find ident in symbol_table.
//then test this bit is set on or not.
bool test_ident_attri_insymbol_table(string ident, string attri, 
                             symbol_table* ptable){
   bool result=false;
   int bitindex = string_tobit(attri);
   
   auto search = (*ptable).find(ident);
   if (search != (*ptable).end()){
      
      //string temp = search->first;
      attr_bitset mybit = search->second->attributes;
      if(mybit.test(bitindex)==true)
        result = true;
        // printf("find %s %s ! \n", temp.c_str(), mybits.c_str());
    }
   return result;
   
}


//convert string to int index of bitset
int string_tobit(string str){
   int index =-1;
    if(strcmp(str.c_str(), "void")==0)     {index = 0;}
    if(strcmp(str.c_str(), "bool")==0)     {index = 1;}
    if(strcmp(str.c_str(), "char")==0)     {index = 2;}
    if(strcmp(str.c_str(), "int")==0)      {index = 3;}
    if(strcmp(str.c_str(), "null")==0)     {index = 4;}
    if(strcmp(str.c_str(), "string")==0)   {index = 5;}
    if(strcmp(str.c_str(), "struct")==0)   {index = 6;}
    if(strcmp(str.c_str(), "array")==0)    {index = 7;}
    if(strcmp(str.c_str(), "function")==0) {index = 8;}
    if(strcmp(str.c_str(), "variable")==0) {index = 9;}
    if(strcmp(str.c_str(), "field")==0)    {index = 10;}
    if(strcmp(str.c_str(), "typeid")==0)   {index = 11;}
    if(strcmp(str.c_str(), "param")==0)    {index = 12;}
    if(strcmp(str.c_str(), "lval")==0)     {index = 13;}
    if(strcmp(str.c_str(), "const")==0)    {index = 14;}
    if(strcmp(str.c_str(), "vreg")==0)     {index = 15;}
    if(strcmp(str.c_str(), "vaddr")==0)    {index = 16;}
  return index; 
}


//receive a int index of bitset, return a corresponding string 
string bit_tostring(int index){
  string temp = "";
  switch(index){
     case 0: 
         temp = "void";      break;
     case 1:
         temp = "bool";      break;
     case 2:
         temp = "char";      break;
     case 3:
         temp = "int";       break;
     case 4: 
         temp = "null";      break;
     case 5:
         temp = "string";    break;
     case 6:
         temp = "struct";    break;
     case 7:
         temp = "array";     break;
     case 8:  
         temp = "function";  break;
     case 9:
         temp = "variable";  break;
     case 10:
         temp = "field";     break;
     case 11:
         temp = "typeid";    break;
     case 12: 
         temp = "parameter"; break;
     case 13:
         temp = "lval";      break;
     case 14:
         temp = "const";     break;
     case 15:
         temp = "vreg";      break;
     case 16: 
         temp = "vaddr";     break;
     default:
         printf("invalid bitset index!\n");
   }

    return temp;
}


int get_bitset_count(string str, symbol_table* atab){
   int count =-1; 
   auto search = (*atab).find(str);
   if (search != (*atab).end()){
    string temp = search->first;
    attr_bitset mybit = search->second->attributes;
    count = mybit.count();
   }
   // printf("bitset count is %d \n", count);
    return count;
}

symbolPtr newSymbol(int filenr, int linenr,
                   int offset){
  symbolPtr anewSym=(symbol*)malloc(sizeof(symbol));
  anewSym->name = NULL;  
  (anewSym->attributes).reset();
  anewSym->fields     = NULL;
  anewSym->filenr     = filenr;
  anewSym->linenr     = linenr;
  anewSym->offset     = offset;
  anewSym->blocknr    = -1;
  anewSym->parameters = NULL;
  //anewSym->name       =" ";
  return anewSym;
}

//symbol_stack astack;
//create a symbol_table pointer to NULL
symbol_table new_stack(){
  symbolPtr newSymPtr = newSymbol(0,0,0);
  string     p       = "";
  symbol_table newtable;
  (newtable).insert({p, newSymPtr});
  return newtable;
}

//push a pair (string, symbol*) into symbol_table according to astree node info.
//The pair has NULL information.
void adding_symtable(string str,int filenr, int linenr,
                     int offset,int block, symbol_table* aSymbolTab){
   
    string strbegin="";
    auto search = (*aSymbolTab).find(strbegin);
    if (search != (*aSymbolTab).end())
       (*aSymbolTab).erase("");    
   //symbolPtr ptr   = newSymbol(filenr, linenr, offset);
  symbolPtr ptr   = newSymbol(filenr, linenr, offset);
  ptr->blocknr=block;
  //string temp= *(node->lexinfo);
  (*aSymbolTab).insert({str, ptr}); 
}

//push a pair (string symbol*) into symbol_table.
//Such pair contains attributes information
//void add_attribute(string str, symbol_table* aSymbolTab){

//find str in symbol_table. print out parameters
void print_para_insymbol(FILE* outfile,string str,symbol_table* ptable){        
  auto search = (*ptable).find(str);
  if (search == (*ptable).end())    
    return;
  if(search->second->parameters==NULL)
    return;
  vector<symbol*>::iterator it;
  for(it=search->second->parameters->begin() ; 
     it < search->second->parameters->end(); it++ ){
        printf("para is \n");
        print_struct_symbol(outfile, *it);
    
   }
  return;

}
//print out content of symbol structure. include bitset, field, parameter 
void print_struct_symbol(FILE* outfile,symbolPtr sym){
  int filenr = sym->filenr;
  int linenr = sym->linenr;
  int offset = sym->offset;
  int blocknr  = sym->blocknr;
  const string* name = (sym->name);
  //string tempa = *name;
  //string namebb = *(sym->name); 
  //int block_nr = sym->block_nr;
  int bit_size = sym->attributes.size();
  
  fprintf(outfile," ?? 155 %s (%d %d %d) {%d}",name, filenr,
                                      linenr, offset, blocknr);
  for (int i=0; i<bit_size; i++) {
     if(sym->attributes.test(i)==true){
        string temp = bit_tostring(i);    
        fprintf(outfile,"%s ", temp.c_str());
     }
  
   }
  
 // print_fields();
 // print_parameter();
 fprintf(outfile,"\n");
  return;
}

//printout a symbol_table content to a file
void print_symtable(FILE* outfile, symbol_table* aTable){
 symbol_table temp = *aTable; 
 printf("table size %ld\n", (*aTable).size());
  for(auto it = (*aTable).begin(); it!= (*aTable).end(); ++it){
 //   if(strcmp(it->first.c_str(), "") !=0 ){
     fprintf(outfile," %s ",(it->first.c_str()) );
     print_struct_symbol(outfile,it->second);
     print_para_insymbol(outfile,it->first,aTable);
   } 
// }
}








/*
symbol_table* pop_stack(stackhead head){
  if(head->count==0)
      return NULL;
  stack tempnode = head->top;
  symbol_table* temp = tempnode->ptr;
  if(head->count==1){head->top = NULL;}
   
  head->top= tempnode->link;
  head->count--; 
  free(tempnode);
  return temp;
}*/
