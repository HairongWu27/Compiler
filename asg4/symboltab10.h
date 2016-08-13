//Id: symbol Table

#ifndef _SYMBOLTAB_H_
#define _SYMBOLTAB_H_

#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <unordered_map>
#include "astree.h"
using namespace std;


#include "auxlib.h"


enum  { ATTR_void, ATTR_bool, ATTR_char, ATTR_int, ATTR_null,
       ATTR_string, ATTR_struct, ATTR_array, ATTR_function,
       ATTR_variable, ATTR_field, ATTR_typeid, ATTR_param,
       ATTR_lval, ATTR_const, ATTR_vreg, ATTR_vaddr,
       ATTR_bitset_size,
};
using attr_bitset = bitset<ATTR_bitset_size>;

struct symbol;
using symbol_table = unordered_map<string*,symbol*>; 
using symbol_entry = symbol_table::value_type;
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
  
  typedef p_stack_head* stackhead;




stackhead newstack();
symbol* newSymbol(int filenr, int linenr, int offset);
void adding_symtable(string* str, int filenr, int linenr,
                int offset,symbol_table* aSymbolTab);
void print_symtable(symbol_table aTable);
#endif


