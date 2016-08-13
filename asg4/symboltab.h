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


enum  { ATTR_void       = 0,  ATTR_bool  = 1,  ATTR_char     = 2, 
        ATTR_int        = 3,  ATTR_null  = 4,  ATTR_string   = 5, 
        ATTR_struct     = 6,  ATTR_array = 7,  ATTR_function = 8,
        ATTR_variable   = 9,  ATTR_field = 10, ATTR_typeid   = 11, 
        ATTR_param      = 12, ATTR_lval  = 13, ATTR_const    = 14, 
        ATTR_vreg       = 15, ATTR_vaddr = 16,
        ATTR_bitset_size= 17,
     };
using attr_bitset = bitset<ATTR_bitset_size>;

struct symbol;
using symbol_table = unordered_map<string,symbol*>; 
using symbol_entry = symbol_table::value_type;
//using vector<symbol_table*> symbol_stack;

//struct field {
   


//}

struct symbol {
     const string* name;
     attr_bitset attributes;
     symbol_table* fields;
    size_t filenr, linenr, offset;
    size_t blocknr;
    vector<symbol*>* parameters;
 };
 
typedef symbol* symbolPtr;
 
 
 
  

void set_bitset_attribute(string str, int index, symbol_table* atab);
void print_bitset(string str, symbol_table* atab);
bool search_ident_insymbol_table(string ident, symbol_table* ptable);
bool test_ident_attri_insymbol_table(string ident, string attri, 
                             symbol_table* ptable);
//string ident_attri_insymbol_table(string ident, symbol_table* atab);
int string_tobit(string str);
string bit_tostring(int index);
int get_bitset_count(string str, symbol_table* atab);
symbolPtr newSymbol(int filenr, int linenr, int offset);
symbol_table new_stack();
void adding_symtable(string str,int filenr, int linenr,
           int offset,int block, symbol_table* aSymbolTab); 
symbol* newSymbol(int filenr, int linenr, int offset);
void adding_symtable(string str, int filenr, int linenr,
                int offset,symbol_table* aSymbolTab);
void print_para_insymbol(FILE* outfile,string str,symbol_table ptable);
void print_struct_symbol(FILE* outfile, symbolPtr sym);
void print_symtable(FILE* outfile, symbol_table* aTable);
#endif


