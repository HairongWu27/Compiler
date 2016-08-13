//astree.cc
#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "astree.h"
#include "stringset.h"
#include "lyutils.h"
#include "symboltab.h"

astree* new_astree (int symbol, int filenr, int linenr, int offset,
                    const char* lexinfo) {
   astree* tree = new astree();
   tree->symbol = symbol;
   tree->filenr = filenr;
   tree->linenr = linenr;
   tree->offset = offset;
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
   stackhead p= newstack();
   root = adopt1 (root, child);
   root->symbol = symbol;
   return root;
}


static void dump_node (FILE* outfile, astree* node) {
   fprintf (outfile, " %s \"%s\" %ld.%ld.%ld ",
             get_yytname (node->symbol),node->lexinfo->c_str(), 
            node->filenr, node->linenr, node->offset);
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
   fprintf (outfile, " |  ");
   for (size_t child = 0; child < root->children.size(); ++child) {
       for(int i=0; i< depth; i++ ) {fprintf (outfile, " |  ");};
       dump_astree_rec (outfile, root->children[child], depth + 1);
   }
   
}
void dump_astree_rec_c (FILE* outfile, astree* root, int depth) {
   if (root == NULL) return;
   dump_node (outfile, root);
   
   fprintf (outfile, "\n"); 
   fprintf (outfile, " |  ");
   for (size_t child = 0; child < root->children.size(); ++child) {
       for(int i=0; i< depth; i++ ) {fprintf (outfile, " |  ");};
       dump_astree_rec (outfile, root->children[child], depth + 1);
   }
    
}


void traverTree(symbol_table* ptable, astree* root, int depth){
   
   
   fprintf(stdout,"xx %s \"%s\"  ",
             get_yytname (root->symbol),root->lexinfo->c_str() );
     /*if (root->symbol==TOK_INT){
        adding_symtable(root, &anewTab);
        }
     if (root->symbol==TOK_NUMBER){
        adding_symtable(root, &anewTab);
        }
     if (root->symbol==TOK_IDENT){
        adding_symtable(root, &anewTab);
        }
     if (root->symbol==TOK_DECLID){
        adding_symtable(root, &anewTab);
        }*/
     if (root->symbol==TOK_VARDECL){
         
                              
        //string temp = root->lexinfo->c_str();
        //string* tempp = &temp;
        symbol_table anewTab; 
        adding_symtable(*(root->lexinfo), root->filenr, root->linenr,
                        root->offset, &anewTab);
        for(size_t child =0; child<root->children.size(); ++child )
            traverTree(&anewTab, root->children[child],  0);
      } 
      for (size_t child =0; child<root->children.size(); ++child )
            traverTree(ptable, root->children[child],  depth+1);    
     if(root->symbol==TOK_INT ||root->symbol ==TOK_INTCON )
        adding_symtable(*(root->lexinfo),root->filenr, root->linenr,
                     root->offset,  ptable); 
     
    //fprintf(stdout,"xx %s \"%s\"  ",
      //       get_yytname (root->symbol),root->lexinfo->c_str() ); 
    // print_symtable(anewTab);
}


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

