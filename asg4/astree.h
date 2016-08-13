#ifndef __ASTREE_H__
#define __ASTREE_H__

#include <string>
#include <vector>
#include "symboltab.h"
//#include "astree.h"
using namespace std;
//using vector<typename symbol_table*> symbol_stack;
#include "auxlib.h"
#include <set>
//extern set<string> typenames;
extern set<string> type_Names; 
extern vector<symbol_table*> stack_sym;

struct astree {
   string structname;
   int symbol;               // token code
   size_t filenr;            // index into filename stack
   size_t linenr;            // line number from source code
   size_t offset;            // offset of token with current line
   size_t blocknr;           // block number
   string attribute1;        // node attribute
   string attribute2;
   string attribute3;
   string attribute4;
   string attribute5;
   const string* lexinfo;    // pointer to lexical information
   vector<astree*> children; // children of this n-way node
};


astree* new_astree (int symbol, int filenr, int linenr, int offset,
                    const char* lexinfo);
astree* new_ASTree(int symbol, astree* root);
//void swap (astree* ptr, int symbol);
astree* adopt1 (astree* root, astree* child);
astree* adopt2 (astree* root, astree* left, astree* right);
astree* adopt3 (astree* root, astree* a1, astree* a2, astree* a3); 
astree* adopt4 (astree* root, astree* a1, astree* a2, astree* a3,
                astree* a4);
void swap (astree* root, int symbol);
bool check_lval(astree* root);
bool check_INT(astree* root);
//bool check_int(astree* root);
bool check_UNSIGN_INT(astree* root);
bool check_sign(astree* root);
bool check_INTCON(astree* root);
//bool check_sign_int(astree* root, astree* parent);


bool check_int_vreg(astree* root, symbol_table* ptable);
bool check_int_intvreg(astree* root,symbol_table* ptable);
bool check_int_variable(astree* root, symbol_table* ptable);
bool check_char_variable(astree* root);
bool check_bool_variable(astree* root);
bool check_string_variable(astree* root);
bool check_BOOLCON(astree* root);
bool check_STRINGCON(astree* root);
bool check_CHARCON(astree* root);
bool check_NULLCON(astree* root);
bool check_ident_insymbol_table(astree* root,symbol_table* ptable);
bool check_any_eqne_any(astree* root);
bool check_ord_char(astree* root);
bool check_chr_int(astree* root);
//bool check_funcall(astree* root, symbol_table* ptable);
bool check_bool_vreg_not(astree* root);
bool check_bool_LELTGEGT(astree* root);
bool check_basetype(string str);
bool check_funcall(astree* root,symbol_table* ptable);
bool find_typeid(string str);
bool check_new_typeid(astree* root);
bool check_new_string_int(astree* root);
bool check_new_base_int(astree* root);
bool check_string_int(astree* root);
astree* adopt1sym (astree* root, astree* child, int symbol);
//void traverTree( astree* root, int depth);
void token_struct(symbol_table* ptable,astree* root, int block);
void token_function(symbol_table* ptable, astree* root, 
                      int block);
void token_block(symbol_table* ptable,astree* root,int block);
//void token_block(symbol_table* ptable, astree* root,
  //                    int block);
void token_prototype(symbol_table* ptable, astree* root,
                      int block);

void adding_sym_tab_attri(symbol_table* ptable,astree* root,
                           int bitsetIndex);
//void adding_int_vreg_tosymbol_tab(symbol_table* ptable,astree* root);
void adding_variable_tosymbol_tab(string attr, symbol_table* ptable, 
                                       astree* root,int block);
void adding_struct_tosymbol_tab(int block, symbol_table* ptable, 
                                              astree* root);
void adding_func_tosymbol_tab(symbol_table* ptable, astree* root,
                                int block);
bool adding_func_name_tosym(symbol_table* ptable, astree* root,
                                int block);
void adding_func_para_tosym(symbol_table* ptable, astree* root,
                                int block);
void  adding_block_tosymbol_tab(symbol_table* ptable, astree* root,
                               int block);
void adding_block_toAst(symbol_table* ptable, astree* root,
                      int block);
void adding_prototype_toAst(symbol_table* ptable, astree* root,
                      int block);
//void adding_bool_vreg_tosymbol_tab(symbol_table* ptable, astree* root);
//void adding_int_vreg_toAst(astree* root);
void adding_one_attribute_toAst(int block,string str, astree* root);
void adding_two_attribute_toAst(int block, string str1,string str2,
                                              astree* root);
void adding_three_attribute_toAst(int block, string str1,
    string str2, string str3, astree* root);
//void adding_four_attribute_toAst(string str1,string str2,
  //              string str3, string str4, astree* root);
void adding_sym_ident_attri_toAst(int block, astree* root,
                                symbol_table* ptable);
//void adding_bool_vreg_toAst(astree* root);
void adding_struct_toAst(astree* root);
void adding_func_toAst(symbol_table* ptable, astree* root,
                      int block);
//void travel_preorder(int block,symbol_table* ptable,
//                         astree* root, int depth);
void traverTree(symbol_table* ptable, astree* root, 
                     int depth, int block);

void dump_astree_rec_c (FILE* outfile, astree* root, int depth);
void dump_astree (FILE* outfile, astree* root);
void yyprint (FILE* outfile, unsigned short toknum, astree* yyvaluep);
void free_ast (astree* tree);
void free_ast2 (astree* tree1, astree* tree2);
void free_ast3 (astree* tree1, astree* tree2, astree* tree3);

RCSH("$Id: astree.h,v 1.3 2013-09-20 12:23:31-07 - - $")
#endif
