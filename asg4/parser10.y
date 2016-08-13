%{
// $Id: parser.y,2015-05-10 Hairong Wu

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "astree.h"

#define YYDEBUG 1
#define YYERROR_VERBOSE 1
#define YYPRINT yyprint
#define YYMALLOC yycalloc

static void* yycalloc (size_t size);

%}

%debug
%defines
%error-verbose
%token-table
%verbose

%destructor { error_destructor ($$); } <>

%token TOK_NUMBER
%token TOK_VOID TOK_BOOL TOK_CHAR TOK_INT TOK_STRING
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_FALSE TOK_TRUE TOK_NULL TOK_NEW TOK_ARRAY
%token TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON

%token TOK_BLOCK TOK_CALL TOK_IFELSE TOK_INITDECL
%token TOK_POS TOK_NEG TOK_NEWARRAY TOK_TYPEID TOK_FIELD
%token TOK_ORD TOK_CHR TOK_ROOT TOK_NOT TOK_FUNCTION 
%token TOK_DECLID TOK_PARAMLIST TOK_VARDECL TOK_INDEX
%token TOK_NEWSTRING TOK_RETURNVOID TOK_PROTOTYPE



%right  TOK_IF "then" TOK_ELSE
%right  '='
%left   TOK_EQ TOK_NE TOK_LT TOK_GT TOK_LE TOK_GE
%left   '+' '-'
%left   '*' '/' '%'
%right  '^'
%right  TOK_POS TOK_NEG TOK_NOT TOK_NEW TOK_ORD TOK_CHR
%left   '.' '['
%nonassoc '('

%start start



%%


start    : program                   { yyparse_astree = $1; } 
         ;
program  : program error ';'         {free_ast ($3); $$ = $1;}
         | program structdef         {$$ = adopt1 ($1, $2);}
         | program function          {$$ = adopt1 ($1, $2);}
         | program statement         {$$ = adopt1 ($1, $2);}
         |                           { $$ = new_parseroot(); }
         ;
structdef:  sds '}'                  {free_ast ($2); $$ = $1;}
         ;
sds      : TOK_STRUCT TOK_IDENT '{'  {swap($2, TOK_TYPEID);free_ast($3);
                                      $$ = adopt1 ($1, $2);}
         | sds fielddecl ';'         {free_ast ($3);$$ = adopt1 ($1, $2);}
         ; 
fielddecl: TOK_BOOL  TOK_IDENT       {swap($2,TOK_FIELD) ;$$ = adopt1 ($1, $2);}
         | TOK_VOID TOK_IDENT        {swap($2,TOK_FIELD) ;$$ = adopt1 ($1, $2);}
         | TOK_CHAR TOK_IDENT        {swap($2,TOK_FIELD) ;$$ = adopt1 ($1, $2);}
         | TOK_INT TOK_IDENT        {swap($2,TOK_FIELD) ;$$ = adopt1 ($1, $2);}
         | TOK_STRING TOK_IDENT      {swap($2,TOK_FIELD) ;$$ = adopt1 ($1, $2);}
         | TOK_IDENT TOK_IDENT       {swap($2,TOK_TYPEID) ;$$ = adopt1 ($1, $2);}
         |TOK_BOOL TOK_ARRAY TOK_IDENT   {swap($3, TOK_FIELD);$$ = adopt2 ($2, $1, $3);}
         |TOK_CHAR TOK_ARRAY TOK_IDENT   {swap($3, TOK_FIELD);$$ = adopt2 ($2, $1, $3);}
         |TOK_INT TOK_ARRAY TOK_IDENT   {swap($3, TOK_FIELD);$$ = adopt2 ($2, $1, $3);}
         |TOK_STRING TOK_ARRAY TOK_IDENT   {swap($3, TOK_FIELD);$$ = adopt2 ($2, $1, $3);}
         |TOK_IDENT TOK_ARRAY TOK_IDENT   {swap($3, TOK_FIELD);$$ = adopt2 ($2, $1, $3);}
         ;
function : identdecl para ')' block  { free_ast($3);
                                     astree* p=new_ASTree(TOK_FUNCTION,$1); 
                                     $$ = adopt3(p,$1,$2, $4);}               
         | identdecl para ')' ';'     {free_ast2 ($3,$4);
                                      astree* p=new_ASTree(TOK_PROTOTYPE,$1);
                                      $$ = adopt2(p,$1,$2);}
         ;
para     : '('                       {swap($1, TOK_PARAMLIST); $$ =  $1;}
         | para ',' identdecl        {free_ast($2); $$ = adopt1($1, $3);}
         | para identdecl            {$$ = adopt1($1,$2);}
         ;
identdecl: TOK_BOOL TOK_IDENT        {swap($2, TOK_DECLID); $$ = adopt1 ($1, $2);}
         |TOK_VOID TOK_IDENT        {swap($2, TOK_DECLID); $$ = adopt1 ($1, $2);}
         | TOK_CHAR TOK_IDENT        {swap($2, TOK_DECLID); $$ = adopt1 ($1, $2);}
         | TOK_INT TOK_IDENT        {swap($2, TOK_DECLID); $$ = adopt1 ($1, $2);}
         | TOK_STRING TOK_IDENT        {swap($2, TOK_DECLID); $$ = adopt1 ($1, $2);}
         | TOK_IDENT TOK_IDENT        {swap($2, TOK_DECLID); $$ = adopt1 ($1, $2);}
         | TOK_CHAR TOK_ARRAY TOK_IDENT  {swap($3, TOK_DECLID); $$ = adopt2 ($2, $1, $3);} 
         | TOK_INT TOK_ARRAY TOK_IDENT  {swap($3, TOK_DECLID); $$ = adopt2 ($2, $1, $3);}
         | TOK_BOOL TOK_ARRAY TOK_IDENT  {swap($3, TOK_DECLID); $$ = adopt2 ($2, $1, $3);}
         |TOK_STRING TOK_ARRAY TOK_IDENT  {swap($3, TOK_DECLID); $$ = adopt2 ($2, $1, $3);}
         |TOK_IDENT TOK_ARRAY TOK_IDENT  {swap($3, TOK_DECLID); $$ = adopt2 ($2, $1, $3);}
         ;
block    : bblock '}'                {free_ast($2);$$ = $1;}
         | ';'                       {swap($1, TOK_BLOCK);$$ = $1;}
         ;
bblock   : '{'                       {swap($1, TOK_BLOCK); $$ = $1;}
         |  bblock statement         { $$ = adopt1($1, $2);}
         ;
statement: block                     {$$ = $1;}
         | expr ';'                  {free_ast($2); $$ = $1;}
         | vardecl                   {$$ = $1;}
         | ifelse                    {$$ = $1;}
         | whileb                    {$$ = $1;}
         | returnb                   {$$ = $1;}
         ;
vardecl  : identdecl '=' expr ';'    {swap($2, TOK_VARDECL);free_ast($4); 
                                      $$ = adopt2 ($2, $1, $3); }
         ;
ifelse   :TOK_IF '(' expr ')' statement %prec "then" {free_ast2($2,$4); $$ = adopt2($1, $3, $5);}
         |TOK_IF '(' expr ')' statement TOK_ELSE statement {free_ast3($2,$4,$6); 
                                                 swap($1, TOK_IFELSE);
                                                 $$ = adopt3($1, $3, $5, $7);}
         ;
whileb   : TOK_WHILE '(' expr ')' statement {free_ast2($2, $4);$$ = adopt2($1, $3, $5);}
         ;
returnb  : TOK_RETURN ';'            {swap($1, TOK_RETURNVOID); 
                                      free_ast($2); $$ = $1;}
         | TOK_RETURN expr ';'       {free_ast($3); $$ = adopt1($1, $2);}
         ;
expr     : expr '=' expr             { $$ = adopt2 ($2, $1, $3); }
         | expr '+' expr             { $$ = adopt2 ($2, $1, $3); }
         | expr '-' expr             { $$ = adopt2 ($2, $1, $3); }
         | expr '*' expr             { $$ = adopt2 ($2, $1, $3); }
         | expr '/' expr             { $$ = adopt2 ($2, $1, $3); }
         | expr '^' expr             { $$ = adopt2 ($2, $1, $3); }
         | expr '%' expr             { $$ = adopt2 ($2, $1, $3); }
         | expr TOK_LT expr          { $$ = adopt2 ($2, $1, $3); }
         | expr TOK_LE expr          { $$ = adopt2 ($2, $1, $3); }
         | expr TOK_GT expr          { $$ = adopt2 ($2, $1, $3); }
         | expr TOK_GE expr          { $$ = adopt2 ($2, $1, $3); }
         | expr TOK_EQ expr          { $$ = adopt2 ($2, $1, $3); }
         | expr TOK_NE expr          { $$ = adopt2 ($2, $1, $3); }
         | '+' expr %prec TOK_POS    { $$ = adopt1sym ($1, $2, TOK_POS); }
         | '-' expr %prec TOK_NEG    { $$ = adopt1sym ($1, $2, TOK_NEG); }
         | '!' expr %prec TOK_NOT    { $$ = adopt1sym ($1, $2, TOK_NOT); }
         | '(' expr ')'              { free_ast2 ($1, $3); $$ = $2; }
         | TOK_ORD expr              { $$ = adopt1($1, $2);      }
         | TOK_CHR expr              { $$ = adopt1($1, $2);      }
         | TOK_IDENT '('')'          { swap($2, TOK_CALL);free_ast($3);
                                       $$ = adopt1($2, $1); }
         | TOK_NEW TOK_IDENT '('')'  {swap($2, TOK_TYPEID);free_ast2($3,$4);
                                          $$ = adopt1($1, $2);}
         |TOK_NEW TOK_STRING '['expr']' {swap($2, TOK_NEWSTRING);
                                          free_ast3($1,$3, $5);
                                          $$ = adopt1 ($2, $4); }
         | allocator                 { $$ = $1;                  }         
         | call                      { $$ = $1;                  }
         | variable                  { $$ = $1;                  }
         | constant                  { $$ = $1;                  }
         ;
allocator: TOK_NEW TOK_INT '[' expr ']'  {swap($1, TOK_NEWARRAY);free_ast2($3,$5);
                                          $$ = adopt2 ($1, $2, $4); }
         |TOK_NEW TOK_CHAR '[' expr ']'  {swap($1, TOK_NEWARRAY);free_ast2($3,$5);
                                          $$ = adopt2 ($1, $2, $4); }
         | TOK_NEW TOK_BOOL '[' expr ']'  {swap($1, TOK_NEWARRAY);;free_ast2($3,$5);
                                          $$ = adopt2 ($1, $2, $4); }
         ;
call     : callb ')'   {free_ast($2); $$= $1; }
         ;
callb    : TOK_IDENT '('expr      {swap($2, TOK_CALL);$$ = adopt2($2, $1,$3); }
         | callb ','expr          {free_ast($2);$$ = adopt1($1, $3);          }
         ;
variable : TOK_IDENT                 { $$ = $1;}
         | expr '[' expr ']'         { swap($2, TOK_INDEX);free_ast($4);
                                       $$ = adopt2($2, $1,$3);}
         | expr '.' TOK_IDENT        { swap($3, TOK_FIELD);free_ast($2);
                                       $$ = adopt1($1, $3);}
         ;
constant : TOK_INTCON                { $$ = $1; } 
         | TOK_CHARCON               { $$ = $1; }
         | TOK_STRINGCON             { $$ = $1; }
         | TOK_FALSE                 { $$ = $1; }
         | TOK_TRUE                  { $$ = $1; }
         | TOK_NULL                  { $$ = $1; }
         ;
%%

const char* get_yytname (int symbol) {
   const char* tname = yytname [YYTRANSLATE (symbol)];
   if (strstr (tname, "TOK_")==tname) tname += 4;
   return tname;
}

bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

static void* yycalloc (size_t size) {
   void* result = calloc (1, size);
   assert (result != NULL);
   return result;
}

RCSC("$Id: parser.y,v 1.6 2015-04-16 17:17:22-07 - - $")

