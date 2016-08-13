
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

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



/* Line 189 of yacc.c  */
#line 93 "yyparse.cc"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif


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


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 184 "yyparse.cc"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   619

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNRULES -- Number of states.  */
#define YYNSTATES  186

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,     2,     2,     2,    56,     2,     2,
      60,    64,    54,    52,    65,    53,    58,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    61,
       2,    51,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    67,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,     2,    62,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    12,    15,    18,    19,    22,
      26,    30,    33,    36,    39,    42,    45,    48,    52,    56,
      60,    64,    68,    73,    78,    80,    84,    87,    90,    93,
      96,    99,   102,   105,   109,   113,   117,   121,   125,   127,
     129,   132,   134,   137,   139,   141,   144,   146,   148,   150,
     152,   157,   163,   171,   177,   180,   184,   188,   192,   196,
     200,   204,   208,   212,   216,   220,   224,   228,   232,   236,
     239,   242,   245,   249,   252,   255,   259,   264,   270,   272,
     274,   276,   278,   284,   290,   296,   299,   303,   307,   309,
     314,   318,   320,   322,   324,   326,   328
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      69,     0,    -1,    70,    -1,    70,     1,    61,    -1,    70,
      71,    -1,    70,    74,    -1,    70,    81,    -1,    -1,    72,
      62,    -1,    13,    25,    63,    -1,    72,    73,    61,    -1,
       5,    25,    -1,     4,    25,    -1,     6,    25,    -1,     7,
      25,    -1,     8,    25,    -1,    25,    25,    -1,     5,    18,
      25,    -1,     6,    18,    25,    -1,     7,    18,    25,    -1,
       8,    18,    25,    -1,    25,    18,    25,    -1,    76,    75,
      64,    78,    -1,    76,    75,    64,    80,    -1,    60,    -1,
      75,    65,    76,    -1,    75,    76,    -1,     5,    25,    -1,
       4,    25,    -1,     6,    25,    -1,     7,    25,    -1,     8,
      25,    -1,    25,    25,    -1,     6,    18,    25,    -1,     7,
      18,    25,    -1,     5,    18,    25,    -1,     8,    18,    25,
      -1,    25,    18,    25,    -1,    78,    -1,    80,    -1,    79,
      62,    -1,    63,    -1,    79,    81,    -1,    61,    -1,    77,
      -1,    86,    61,    -1,    82,    -1,    83,    -1,    84,    -1,
      85,    -1,    76,    51,    86,    61,    -1,     9,    60,    86,
      64,    81,    -1,     9,    60,    86,    64,    81,    10,    81,
      -1,    11,    60,    86,    64,    81,    -1,    12,    61,    -1,
      12,    86,    61,    -1,    86,    51,    86,    -1,    86,    52,
      86,    -1,    86,    53,    86,    -1,    86,    54,    86,    -1,
      86,    55,    86,    -1,    86,    57,    86,    -1,    86,    56,
      86,    -1,    86,    21,    86,    -1,    86,    22,    86,    -1,
      86,    23,    86,    -1,    86,    24,    86,    -1,    86,    19,
      86,    -1,    86,    20,    86,    -1,    52,    86,    -1,    53,
      86,    -1,    66,    86,    -1,    60,    86,    64,    -1,    38,
      86,    -1,    39,    86,    -1,    25,    60,    64,    -1,    17,
      25,    60,    64,    -1,    17,     8,    59,    86,    67,    -1,
      87,    -1,    88,    -1,    90,    -1,    91,    -1,    17,     7,
      59,    86,    67,    -1,    17,     6,    59,    86,    67,    -1,
      17,     5,    59,    86,    67,    -1,    89,    64,    -1,    25,
      60,    86,    -1,    89,    65,    86,    -1,    25,    -1,    86,
      59,    86,    67,    -1,    86,    58,    25,    -1,    26,    -1,
      27,    -1,    28,    -1,    14,    -1,    15,    -1,    16,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    60,    60,    62,    63,    64,    65,    66,    68,    70,
      72,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    86,    89,    93,    94,    95,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   109,   110,
     112,   114,   115,   117,   119,   120,   121,   122,   123,   124,
     126,   129,   130,   134,   136,   138,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   161,   163,   166,   167,
     168,   169,   171,   173,   175,   178,   180,   181,   183,   184,
     186,   189,   190,   191,   192,   193,   194
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_NUMBER", "TOK_VOID", "TOK_BOOL",
  "TOK_CHAR", "TOK_INT", "TOK_STRING", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_RETURN", "TOK_STRUCT", "TOK_FALSE", "TOK_TRUE", "TOK_NULL",
  "TOK_NEW", "TOK_ARRAY", "TOK_EQ", "TOK_NE", "TOK_LT", "TOK_LE", "TOK_GT",
  "TOK_GE", "TOK_IDENT", "TOK_INTCON", "TOK_CHARCON", "TOK_STRINGCON",
  "TOK_BLOCK", "TOK_CALL", "TOK_IFELSE", "TOK_INITDECL", "TOK_POS",
  "TOK_NEG", "TOK_NEWARRAY", "TOK_TYPEID", "TOK_FIELD", "TOK_ORD",
  "TOK_CHR", "TOK_ROOT", "TOK_NOT", "TOK_FUNCTION", "TOK_DECLID",
  "TOK_PARAMLIST", "TOK_VARDECL", "TOK_INDEX", "TOK_NEWSTRING",
  "TOK_RETURNVOID", "TOK_PROTOTYPE", "\"then\"", "'='", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'^'", "'.'", "'['", "'('", "';'", "'}'", "'{'",
  "')'", "','", "'!'", "']'", "$accept", "start", "program", "structdef",
  "sds", "fielddecl", "function", "para", "identdecl", "block", "blocka",
  "bblock", "blockb", "statement", "vardecl", "ifelse", "whileb",
  "returnb", "expr", "allocator", "call", "callb", "variable", "constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    61,    43,    45,    42,    47,    37,    94,    46,    91,
      40,    59,   125,   123,    41,    44,    33,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    70,    70,    70,    70,    70,    71,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    74,    74,    75,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    77,    77,
      78,    79,    79,    80,    81,    81,    81,    81,    81,    81,
      82,    83,    83,    84,    85,    85,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    87,    87,    87,    88,    89,    89,    90,    90,
      90,    91,    91,    91,    91,    91,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     2,     2,     2,     0,     2,     3,
       3,     2,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     4,     4,     1,     3,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     1,     1,
       2,     1,     2,     1,     1,     2,     1,     1,     1,     1,
       4,     5,     7,     5,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     3,     2,     2,     3,     4,     5,     1,     1,
       1,     1,     5,     5,     5,     2,     3,     3,     1,     4,
       3,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,     0,    88,    91,
      92,    93,     0,     0,     0,     0,     0,    43,    41,     0,
       4,     0,     5,     0,    44,    38,     0,    39,     6,    46,
      47,    48,    49,     0,    78,    79,     0,    80,    81,     3,
      28,     0,    27,     0,    29,     0,    30,     0,    31,     0,
       0,    88,    54,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,    73,    74,    69,    70,     0,    71,     0,
       0,     0,     0,     0,     0,     8,     0,     0,    24,     0,
      40,     0,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,    85,
       0,    35,    33,    34,    36,     0,     0,    55,     9,     0,
       0,     0,     0,     0,    37,    75,    86,    72,    12,     0,
      11,     0,    13,     0,    14,     0,    15,     0,    16,    10,
       0,     0,     0,     0,    26,    67,    68,    63,    64,    65,
      66,    56,    57,    58,    59,    60,    62,    61,    90,     0,
      87,     0,     0,     0,     0,     0,     0,    76,    17,    18,
      19,    20,    21,    50,    22,    23,    25,    89,    51,    53,
      84,    83,    82,    77,     0,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    30,    31,    86,    32,    89,    91,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -43
static const yytype_int16 yypact[] =
{
     -43,    24,   145,   -43,   -13,    32,    28,    29,    41,    51,
      11,    42,    12,    94,   -43,   -43,   -43,    36,   -11,   -43,
     -43,   -43,   291,   291,   291,   291,   291,   -43,   -43,   291,
     -43,     5,   -43,   -15,   -43,   -43,   208,   -43,   -43,   -43,
     -43,   -43,   -43,   495,   -43,   -43,    20,   -43,   -43,   -43,
     -43,    96,   -43,    97,   -43,    98,   -43,    99,   -43,   291,
     291,    75,   -43,   517,    71,    77,    78,    79,    80,    81,
     115,   -43,   275,    46,    46,    46,    46,   425,    46,   118,
      52,    56,    57,    61,    62,   -43,    83,   291,   -43,    -2,
     -43,   104,   -43,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   122,   291,   -43,   -43,
     291,   -43,   -43,   -43,   -43,   449,   471,   -43,   -43,   291,
     291,   291,   291,   100,   -43,   -43,   560,   -43,   -43,   138,
     -43,   140,   -43,   141,   -43,   142,   -43,   143,   -43,   -43,
     538,   102,    -3,    27,   -43,    55,    55,    55,    55,    55,
      55,   560,    74,    74,   -42,   -42,   -42,   -42,   -43,   326,
     560,   271,   271,   343,   367,   384,   408,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   159,   -43,
     -43,   -43,   -43,   -43,   271,   -43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,    -1,   -43,
      33,   -43,    34,   -36,   -43,   -43,   -43,   -43,    -4,   -43,
     -43,   -43,   -43,   -43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -3
static const yytype_int16 yytable[] =
{
      92,    33,     5,     6,     7,     8,     9,    70,    63,    79,
      80,    81,    82,    83,    71,   105,   106,   107,    73,    74,
      75,    76,    77,   141,     3,    78,    14,    15,    16,    17,
      84,     5,     6,     7,     8,     9,    87,    61,    19,    20,
      21,    65,    66,    67,    68,    88,    51,    53,    49,    72,
      22,    23,   141,    52,    54,   115,   116,    50,    27,    55,
      28,    69,   142,   143,    24,    25,    56,    85,   126,    57,
     129,    59,    26,    62,   131,   133,    58,   130,    29,   135,
     137,   132,   134,   140,   109,   110,   136,   138,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    60,   159,   106,   107,   160,   100,   101,   102,
     103,   104,   105,   106,   107,   163,   164,   165,   166,    64,
      70,   111,   112,   113,   114,   178,   179,    71,   102,   103,
     104,   105,   106,   107,   118,    72,   119,   120,   121,   122,
     124,   123,   176,   128,   139,    -2,     4,   158,   185,     5,
       6,     7,     8,     9,    10,    87,    11,    12,    13,    14,
      15,    16,    17,   168,   167,   169,   170,   171,   172,   184,
      18,    19,    20,    21,     0,   174,   175,     0,     0,     0,
       0,     0,     0,    22,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,     0,
       0,     0,     0,     0,     0,    26,    27,     0,    28,     0,
       0,    29,     5,     6,     7,     8,     9,    10,     0,    11,
      12,     0,    14,    15,    16,    17,     0,     0,     0,     0,
       0,     0,     0,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    25,     0,     0,     0,     0,     0,     0,    26,    27,
      90,    28,     0,     0,    29,     5,     6,     7,     8,     9,
      10,     0,    11,    12,     0,    14,    15,    16,    17,    14,
      15,    16,    17,     0,     0,     0,    18,    19,    20,    21,
      61,    19,    20,    21,     0,    14,    15,    16,    17,    22,
      23,     0,     0,    22,    23,     0,    61,    19,    20,    21,
       0,     0,     0,    24,    25,     0,     0,    24,    25,    22,
      23,    26,    27,     0,    28,    26,     0,    29,     0,   125,
       0,    29,     0,    24,    25,    93,    94,    95,    96,    97,
      98,    26,     0,     0,     0,     0,     0,    29,     0,     0,
       0,     0,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    93,    94,    95,    96,
      97,    98,     0,   177,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    93,    94,    95,    96,    97,    98,     0,
     180,     0,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    93,    94,    95,
      96,    97,    98,     0,   181,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    93,    94,    95,    96,    97,    98,
       0,   182,     0,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    93,    94,
      95,    96,    97,    98,     0,   183,    99,   100,   101,   102,
     103,   104,   105,   106,   107,     0,     0,     0,     0,   127,
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     0,
       0,     0,     0,   161,    93,    94,    95,    96,    97,    98,
       0,     0,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,     0,     0,     0,   162,    93,    94,    95,    96,
      97,    98,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,   105,   106,   107,     0,   108,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,     0,   117,    93,
      94,    95,    96,    97,    98,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,   106,   107,     0,   173,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,   105,   106,   107
};

static const yytype_int16 yycheck[] =
{
      36,     2,     4,     5,     6,     7,     8,    18,    12,     4,
       5,     6,     7,     8,    25,    57,    58,    59,    22,    23,
      24,    25,    26,    25,     0,    29,    14,    15,    16,    17,
      25,     4,     5,     6,     7,     8,    51,    25,    26,    27,
      28,     5,     6,     7,     8,    60,    18,    18,    61,    60,
      38,    39,    25,    25,    25,    59,    60,    25,    61,    18,
      63,    25,    64,    65,    52,    53,    25,    62,    72,    18,
      18,    60,    60,    61,    18,    18,    25,    25,    66,    18,
      18,    25,    25,    87,    64,    65,    25,    25,    89,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    60,   107,    58,    59,   110,    52,    53,    54,
      55,    56,    57,    58,    59,   119,   120,   121,   122,    25,
      18,    25,    25,    25,    25,   161,   162,    25,    54,    55,
      56,    57,    58,    59,    63,    60,    59,    59,    59,    59,
      25,    60,   143,    25,    61,     0,     1,    25,   184,     4,
       5,     6,     7,     8,     9,    51,    11,    12,    13,    14,
      15,    16,    17,    25,    64,    25,    25,    25,    25,    10,
      25,    26,    27,    28,    -1,   142,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    63,    -1,
      -1,    66,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    -1,    -1,    66,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    14,    15,    16,    17,    14,
      15,    16,    17,    -1,    -1,    -1,    25,    26,    27,    28,
      25,    26,    27,    28,    -1,    14,    15,    16,    17,    38,
      39,    -1,    -1,    38,    39,    -1,    25,    26,    27,    28,
      -1,    -1,    -1,    52,    53,    -1,    -1,    52,    53,    38,
      39,    60,    61,    -1,    63,    60,    -1,    66,    -1,    64,
      -1,    66,    -1,    52,    53,    19,    20,    21,    22,    23,
      24,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    19,    20,    21,    22,
      23,    24,    -1,    67,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    19,    20,    21,    22,    23,    24,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    19,    20,    21,
      22,    23,    24,    -1,    67,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    19,    20,    21,    22,    23,    24,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    19,    20,
      21,    22,    23,    24,    -1,    67,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    64,    19,    20,    21,    22,    23,    24,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    69,    70,     0,     1,     4,     5,     6,     7,     8,
       9,    11,    12,    13,    14,    15,    16,    17,    25,    26,
      27,    28,    38,    39,    52,    53,    60,    61,    63,    66,
      71,    72,    74,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    61,
      25,    18,    25,    18,    25,    18,    25,    18,    25,    60,
      60,    25,    61,    86,    25,     5,     6,     7,     8,    25,
      18,    25,    60,    86,    86,    86,    86,    86,    86,     4,
       5,     6,     7,     8,    25,    62,    73,    51,    60,    75,
      62,    76,    81,    19,    20,    21,    22,    23,    24,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    61,    64,
      65,    25,    25,    25,    25,    86,    86,    61,    63,    59,
      59,    59,    59,    60,    25,    64,    86,    64,    25,    18,
      25,    18,    25,    18,    25,    18,    25,    18,    25,    61,
      86,    25,    64,    65,    76,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    25,    86,
      86,    64,    64,    86,    86,    86,    86,    64,    25,    25,
      25,    25,    25,    61,    78,    80,    76,    67,    81,    81,
      67,    67,    67,    67,    10,    81
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 3: /* "TOK_NUMBER" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1337 "yyparse.cc"
	break;
      case 4: /* "TOK_VOID" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1346 "yyparse.cc"
	break;
      case 5: /* "TOK_BOOL" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1355 "yyparse.cc"
	break;
      case 6: /* "TOK_CHAR" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1364 "yyparse.cc"
	break;
      case 7: /* "TOK_INT" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1373 "yyparse.cc"
	break;
      case 8: /* "TOK_STRING" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1382 "yyparse.cc"
	break;
      case 9: /* "TOK_IF" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1391 "yyparse.cc"
	break;
      case 10: /* "TOK_ELSE" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1400 "yyparse.cc"
	break;
      case 11: /* "TOK_WHILE" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1409 "yyparse.cc"
	break;
      case 12: /* "TOK_RETURN" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1418 "yyparse.cc"
	break;
      case 13: /* "TOK_STRUCT" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1427 "yyparse.cc"
	break;
      case 14: /* "TOK_FALSE" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1436 "yyparse.cc"
	break;
      case 15: /* "TOK_TRUE" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1445 "yyparse.cc"
	break;
      case 16: /* "TOK_NULL" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1454 "yyparse.cc"
	break;
      case 17: /* "TOK_NEW" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1463 "yyparse.cc"
	break;
      case 18: /* "TOK_ARRAY" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1472 "yyparse.cc"
	break;
      case 19: /* "TOK_EQ" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1481 "yyparse.cc"
	break;
      case 20: /* "TOK_NE" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1490 "yyparse.cc"
	break;
      case 21: /* "TOK_LT" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1499 "yyparse.cc"
	break;
      case 22: /* "TOK_LE" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1508 "yyparse.cc"
	break;
      case 23: /* "TOK_GT" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1517 "yyparse.cc"
	break;
      case 24: /* "TOK_GE" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1526 "yyparse.cc"
	break;
      case 25: /* "TOK_IDENT" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1535 "yyparse.cc"
	break;
      case 26: /* "TOK_INTCON" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1544 "yyparse.cc"
	break;
      case 27: /* "TOK_CHARCON" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1553 "yyparse.cc"
	break;
      case 28: /* "TOK_STRINGCON" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1562 "yyparse.cc"
	break;
      case 29: /* "TOK_BLOCK" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1571 "yyparse.cc"
	break;
      case 30: /* "TOK_CALL" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1580 "yyparse.cc"
	break;
      case 31: /* "TOK_IFELSE" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1589 "yyparse.cc"
	break;
      case 32: /* "TOK_INITDECL" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1598 "yyparse.cc"
	break;
      case 33: /* "TOK_POS" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1607 "yyparse.cc"
	break;
      case 34: /* "TOK_NEG" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1616 "yyparse.cc"
	break;
      case 35: /* "TOK_NEWARRAY" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1625 "yyparse.cc"
	break;
      case 36: /* "TOK_TYPEID" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1634 "yyparse.cc"
	break;
      case 37: /* "TOK_FIELD" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1643 "yyparse.cc"
	break;
      case 38: /* "TOK_ORD" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1652 "yyparse.cc"
	break;
      case 39: /* "TOK_CHR" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1661 "yyparse.cc"
	break;
      case 40: /* "TOK_ROOT" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1670 "yyparse.cc"
	break;
      case 41: /* "TOK_NOT" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1679 "yyparse.cc"
	break;
      case 42: /* "TOK_FUNCTION" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1688 "yyparse.cc"
	break;
      case 43: /* "TOK_DECLID" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1697 "yyparse.cc"
	break;
      case 44: /* "TOK_PARAMLIST" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1706 "yyparse.cc"
	break;
      case 45: /* "TOK_VARDECL" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1715 "yyparse.cc"
	break;
      case 46: /* "TOK_INDEX" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1724 "yyparse.cc"
	break;
      case 47: /* "TOK_NEWSTRING" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1733 "yyparse.cc"
	break;
      case 48: /* "TOK_RETURNVOID" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1742 "yyparse.cc"
	break;
      case 49: /* "TOK_PROTOTYPE" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1751 "yyparse.cc"
	break;
      case 50: /* "\"then\"" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1760 "yyparse.cc"
	break;
      case 51: /* "'='" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1769 "yyparse.cc"
	break;
      case 52: /* "'+'" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1778 "yyparse.cc"
	break;
      case 53: /* "'-'" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1787 "yyparse.cc"
	break;
      case 54: /* "'*'" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1796 "yyparse.cc"
	break;
      case 55: /* "'/'" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1805 "yyparse.cc"
	break;
      case 56: /* "'%'" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1814 "yyparse.cc"
	break;
      case 57: /* "'^'" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1823 "yyparse.cc"
	break;
      case 58: /* "'.'" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1832 "yyparse.cc"
	break;
      case 59: /* "'['" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1841 "yyparse.cc"
	break;
      case 60: /* "'('" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1850 "yyparse.cc"
	break;
      case 61: /* "';'" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1859 "yyparse.cc"
	break;
      case 62: /* "'}'" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1868 "yyparse.cc"
	break;
      case 63: /* "'{'" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1877 "yyparse.cc"
	break;
      case 64: /* "')'" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1886 "yyparse.cc"
	break;
      case 65: /* "','" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1895 "yyparse.cc"
	break;
      case 66: /* "'!'" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1904 "yyparse.cc"
	break;
      case 67: /* "']'" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1913 "yyparse.cc"
	break;
      case 69: /* "start" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1922 "yyparse.cc"
	break;
      case 70: /* "program" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1931 "yyparse.cc"
	break;
      case 71: /* "structdef" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1940 "yyparse.cc"
	break;
      case 72: /* "sds" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1949 "yyparse.cc"
	break;
      case 73: /* "fielddecl" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1958 "yyparse.cc"
	break;
      case 74: /* "function" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1967 "yyparse.cc"
	break;
      case 75: /* "para" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1976 "yyparse.cc"
	break;
      case 76: /* "identdecl" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1985 "yyparse.cc"
	break;
      case 77: /* "block" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1994 "yyparse.cc"
	break;
      case 78: /* "blocka" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2003 "yyparse.cc"
	break;
      case 79: /* "bblock" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2012 "yyparse.cc"
	break;
      case 80: /* "blockb" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2021 "yyparse.cc"
	break;
      case 81: /* "statement" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2030 "yyparse.cc"
	break;
      case 82: /* "vardecl" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2039 "yyparse.cc"
	break;
      case 83: /* "ifelse" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2048 "yyparse.cc"
	break;
      case 84: /* "whileb" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2057 "yyparse.cc"
	break;
      case 85: /* "returnb" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2066 "yyparse.cc"
	break;
      case 86: /* "expr" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2075 "yyparse.cc"
	break;
      case 87: /* "allocator" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2084 "yyparse.cc"
	break;
      case 88: /* "call" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2093 "yyparse.cc"
	break;
      case 89: /* "callb" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2102 "yyparse.cc"
	break;
      case 90: /* "variable" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2111 "yyparse.cc"
	break;
      case 91: /* "constant" */

/* Line 1000 of yacc.c  */
#line 26 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2120 "yyparse.cc"
	break;

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 60 "parser.y"
    { yyparse_astree = (yyvsp[(1) - (1)]); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 62 "parser.y"
    {free_ast ((yyvsp[(3) - (3)])); (yyval) = (yyvsp[(1) - (3)]);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 63 "parser.y"
    {(yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 64 "parser.y"
    {(yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 65 "parser.y"
    {(yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 66 "parser.y"
    { (yyval) = new_parseroot(); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 68 "parser.y"
    {free_ast ((yyvsp[(2) - (2)])); (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 70 "parser.y"
    {swap((yyvsp[(2) - (3)]), TOK_TYPEID);free_ast((yyvsp[(3) - (3)]));
                                      (yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 72 "parser.y"
    {free_ast ((yyvsp[(3) - (3)]));(yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 74 "parser.y"
    {swap((yyvsp[(2) - (2)]),TOK_FIELD) ;(yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 75 "parser.y"
    {swap((yyvsp[(2) - (2)]),TOK_FIELD) ;(yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    {swap((yyvsp[(2) - (2)]),TOK_FIELD) ;(yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 77 "parser.y"
    {swap((yyvsp[(2) - (2)]),TOK_FIELD) ;(yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    {swap((yyvsp[(2) - (2)]),TOK_FIELD) ;(yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    {swap((yyvsp[(2) - (2)]),TOK_TYPEID) ;(yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    {swap((yyvsp[(3) - (3)]), TOK_FIELD);(yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    {swap((yyvsp[(3) - (3)]), TOK_FIELD);(yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    {swap((yyvsp[(3) - (3)]), TOK_FIELD);(yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    {swap((yyvsp[(3) - (3)]), TOK_FIELD);(yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    {swap((yyvsp[(3) - (3)]), TOK_FIELD);(yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 86 "parser.y"
    { free_ast((yyvsp[(3) - (4)]));
                                     astree* p=new_ASTree(TOK_FUNCTION,(yyvsp[(1) - (4)])); 
                                     (yyval) = adopt3(p,(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    {free_ast2 ((yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));
                                      astree* p=new_ASTree(TOK_PROTOTYPE,(yyvsp[(1) - (4)]));
                                      (yyval) = adopt2(p,(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    {swap((yyvsp[(1) - (1)]), TOK_PARAMLIST); (yyval) =  (yyvsp[(1) - (1)]);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    {free_ast((yyvsp[(2) - (3)])); (yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    {(yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    {swap((yyvsp[(2) - (2)]), TOK_DECLID); (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    {swap((yyvsp[(2) - (2)]), TOK_DECLID); (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    {swap((yyvsp[(2) - (2)]), TOK_DECLID); (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    {swap((yyvsp[(2) - (2)]), TOK_DECLID); (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    {swap((yyvsp[(2) - (2)]), TOK_DECLID); (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    {swap((yyvsp[(2) - (2)]), TOK_DECLID); (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    {swap((yyvsp[(3) - (3)]), TOK_DECLID); (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    {swap((yyvsp[(3) - (3)]), TOK_DECLID); (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    {swap((yyvsp[(3) - (3)]), TOK_DECLID); (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    {swap((yyvsp[(3) - (3)]), TOK_DECLID); (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    {swap((yyvsp[(3) - (3)]), TOK_DECLID); (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    {free_ast((yyvsp[(2) - (2)]));(yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    {swap((yyvsp[(1) - (1)]), TOK_BLOCK); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    {swap((yyvsp[(1) - (1)]), TOK_BLOCK);(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {free_ast((yyvsp[(2) - (2)])); (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    {swap((yyvsp[(2) - (4)]), TOK_VARDECL);free_ast((yyvsp[(4) - (4)])); 
                                      (yyval) = adopt2 ((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    {free_ast2((yyvsp[(2) - (5)]),(yyvsp[(4) - (5)])); (yyval) = adopt2((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {free_ast3((yyvsp[(2) - (7)]),(yyvsp[(4) - (7)]),(yyvsp[(6) - (7)])); 
                                                 swap((yyvsp[(1) - (7)]), TOK_IFELSE);
                                                 (yyval) = adopt3((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    {free_ast2((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));(yyval) = adopt2((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    {swap((yyvsp[(1) - (2)]), TOK_RETURNVOID); 
                                      free_ast((yyvsp[(2) - (2)])); (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    {free_ast((yyvsp[(3) - (3)])); (yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 148 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), TOK_POS); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), TOK_NEG); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), TOK_NOT); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    { free_ast2 ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));      ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));      ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    { swap((yyvsp[(2) - (3)]), TOK_CALL);free_ast((yyvsp[(3) - (3)]));
                                       (yyval) = adopt1((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)])); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    {swap((yyvsp[(2) - (4)]), TOK_TYPEID);free_ast2((yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));
                                          (yyval) = adopt1((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {swap((yyvsp[(2) - (5)]), TOK_NEWSTRING);
                                          free_ast3((yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
                                          (yyval) = adopt1 ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]);                  ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]);                  ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]);                  ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]);                  ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {swap((yyvsp[(1) - (5)]), TOK_NEWARRAY);free_ast2((yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));
                                          (yyval) = adopt2 ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    {swap((yyvsp[(1) - (5)]), TOK_NEWARRAY);free_ast2((yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));
                                          (yyval) = adopt2 ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 175 "parser.y"
    {swap((yyvsp[(1) - (5)]), TOK_NEWARRAY);;free_ast2((yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));
                                          (yyval) = adopt2 ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    {free_ast((yyvsp[(2) - (2)])); (yyval)= (yyvsp[(1) - (2)]); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    {swap((yyvsp[(2) - (3)]), TOK_CALL);(yyval) = adopt2((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {free_ast((yyvsp[(2) - (3)]));(yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));          ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    { swap((yyvsp[(2) - (4)]), TOK_INDEX);free_ast((yyvsp[(4) - (4)]));
                                       (yyval) = adopt2((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 186 "parser.y"
    { swap((yyvsp[(3) - (3)]), TOK_FIELD);free_ast((yyvsp[(2) - (3)]));
                                       (yyval) = adopt2((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;



/* Line 1455 of yacc.c  */
#line 3108 "yyparse.cc"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 196 "parser.y"


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


