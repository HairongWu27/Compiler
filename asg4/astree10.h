#ifndef __ASTREE_H__
#define __ASTREE_H__

#include <string>
#include <vector>
#include "symboltab.h"
//#include "astree.h"
using namespace std;

#include "auxlib.h"

struct astree {
   int symbol;               // token code
   size_t filenr;            // index into filename stack
   size_t linenr;            // line number from source code
   size_t offset;            // offset of token with current line
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
astree* adopt1sym (astree* root, astree* child, int symbol);
//void traverTree( astree* root, int depth);
void traverTree(symbol_table* ptable, astree* root, int depth);
void dump_astree_rec_c (FILE* outfile, astree* root, int depth);
void dump_astree (FILE* outfile, astree* root);
void yyprint (FILE* outfile, unsigned short toknum, astree* yyvaluep);
void free_ast (astree* tree);
void free_ast2 (astree* tree1, astree* tree2);
void free_ast3 (astree* tree1, astree* tree2, astree* tree3);

RCSH("$Id: astree.h,v 1.3 2013-09-20 12:23:31-07 - - $")
#endif
