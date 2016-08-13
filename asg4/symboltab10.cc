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




//using attr_bitset = bitset<ATTR_bitset_size>;

//struct symbol;
//using symbol_table = unordered_map<string,symbol*>;
//using symbol_entry = symbol_table::value_type;

//struct of symbol
/* 
struct symbol {
   attr_bitset attributes;
   symbol_table* fields;
   size_t filenr, linenr, offset;
   size_t blocknr;
   vector<symbol*>* parameters;
};

typedef symbol* symbolPtr; 

struct p_stack_node{//stack node
   symbol_table* ptr; 
   p_stack_node* link;
};

typedef p_stack_node* stack;

struct p_stack_head{//stack head
  int count;
  stack top;  
};

typedef p_stack_head* stackhead;*/

/*stack new_stack_node(){
  stack newNode= (stack)malloc(sizeof(p_stack_node));
  newNode->ptr =  NULL;
  newNode->link = NULL;
  return newNode;
}*/

stackhead newstack(){
  stackhead aStackHead =(stackhead) malloc(sizeof(p_stack_head));
  aStackHead->count = 0;
  aStackHead->top   = NULL;
  return aStackHead;
 }

void push_stack(stackhead head, symbol_table* aptr){
  stack newNode = (stack)malloc(sizeof(p_stack_node));
  newNode->ptr  = aptr;
  newNode->link = NULL;
  
  if (head->count >0){ newNode->link = head->top;}
   head->top= newNode;
   head->count++;
}

symbolPtr newSymbol( int filenr, int linenr, 
                    int offset){
  symbolPtr anewSym=(symbol*)malloc(sizeof(symbol));
  (anewSym->attributes).set();
  anewSym->fields     = NULL;
  anewSym->filenr     = filenr;
  anewSym->linenr     = linenr;
  anewSym->offset     = offset;
  anewSym->blocknr    = -1;
  anewSym->parameters = NULL;
  return anewSym;
}

//push a pair (string*, symbol*) into symbol_table according to astree node info.
void adding_symtable(string* str,int filenr, int linenr,
                     int offset, symbol_table* aSymbolTab){
  
  symbolPtr ptr   = newSymbol(filenr, linenr, offset);
  //string temp= *(node->lexinfo);
  //string* p = &temp;
  (*aSymbolTab).insert({str, ptr}); 
}

//travels a hash table-symbol_table, print out the content
void print_symtable(symbol_table aTable){
  printf(" %ld", aTable.size());
  for(auto it = aTable.begin(); it != aTable.end(); ++it)
      printf("+++%s \n",it->first->c_str() );

}

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
}
