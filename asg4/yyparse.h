
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_NUMBER = 258,
     TOK_VOID = 259,
     TOK_BOOL = 260,
     TOK_CHAR = 261,
     TOK_INT = 262,
     TOK_STRING = 263,
     TOK_IF = 264,
     TOK_ELSE = 265,
     TOK_WHILE = 266,
     TOK_RETURN = 267,
     TOK_STRUCT = 268,
     TOK_FALSE = 269,
     TOK_TRUE = 270,
     TOK_NULL = 271,
     TOK_NEW = 272,
     TOK_ARRAY = 273,
     TOK_EQ = 274,
     TOK_NE = 275,
     TOK_LT = 276,
     TOK_LE = 277,
     TOK_GT = 278,
     TOK_GE = 279,
     TOK_IDENT = 280,
     TOK_INTCON = 281,
     TOK_CHARCON = 282,
     TOK_STRINGCON = 283,
     TOK_BLOCK = 284,
     TOK_CALL = 285,
     TOK_IFELSE = 286,
     TOK_INITDECL = 287,
     TOK_POS = 288,
     TOK_NEG = 289,
     TOK_NEWARRAY = 290,
     TOK_TYPEID = 291,
     TOK_FIELD = 292,
     TOK_ORD = 293,
     TOK_CHR = 294,
     TOK_ROOT = 295,
     TOK_NOT = 296,
     TOK_FUNCTION = 297,
     TOK_DECLID = 298,
     TOK_PARAMLIST = 299,
     TOK_VARDECL = 300,
     TOK_INDEX = 301,
     TOK_NEWSTRING = 302,
     TOK_RETURNVOID = 303,
     TOK_PROTOTYPE = 304
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


