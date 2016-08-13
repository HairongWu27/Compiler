%{
// $Id: scanner.l,v 1.5 2015-04-16 17:17:51-07 - - $

#include "auxlib.h"
#include "lyutils.h"

#define YY_USER_ACTION  { scanner_useraction (); }

%}

%option 8bit
%option debug
%option nodefault
%option nounput
%option noyywrap
%option verbose
%option warn

LETTER          [A-Za-z_]
DIGIT           [0-9]
NUMBER          ({DIGIT}+)
CHAR            ('([^\\’\n]|\\[\\’"0nt])')
BADCHAR         ('([^\\’\n]|\\.)'?)
STRING          (\"([^\\"\n]|\\[\\’"0nt])*\")
BADSTRING       (\"([^\\"\n]|\\.)*(\")?)
IDENT           ({LETTER}({LETTER}|{DIGIT})*)
BADIDENT        ({DIGIT}({LETTER}|{DIGIT})*)

%%

"#".*           { scanner_include();                     }
"="             { return yylval_token ('=');             }
"+"             { return yylval_token ('+');             }
"-"             { return yylval_token ('-');             }
"*"             { return yylval_token ('*');             }
"/"             { return yylval_token ('/');             }
"^"             { return yylval_token ('^');             }
"%"             { return yylval_token ('%');             }
"!"             { return yylval_token ('!');             }
":"             { return yylval_token (':');             }
"("             { return yylval_token ('(');             } 
")"             { return yylval_token (')');             }
"["             { return yylval_token ('[');             }
"]"             { return yylval_token (']');             }
"{"             { return yylval_token ('{');             }
"}"             { return yylval_token ('}');             }
","             { return yylval_token (',');             }
"."             { return yylval_token ('.');             }
";"             { return yylval_token (';');             }
"|"             { return yylval_token ('|');             }
"?"             { return yylval_token ('?');             }
"&"             { return yylval_token ('&');             }
"\\"            { return yylval_token ('\\');            }
"\""            { return yylval_token ('\"');            }
"\'"            { return yylval_token ('\'');            }
"[]"            { return yylval_token (TOK_ARRAY);       }
"<"             { return yylval_token (TOK_LT);          }
">"             { return yylval_token (TOK_GT);          }
"<="            { return yylval_token (TOK_LE);          }
">="            { return yylval_token (TOK_GE);          }
"=="            { return yylval_token (TOK_EQ);          }
"!="            { return yylval_token (TOK_NE);          }
void            { return yylval_token (TOK_VOID);        }
bool            { return yylval_token (TOK_BOOL);        }
char            { return yylval_token (TOK_CHAR);        }
int             { return yylval_token (TOK_INT);         }
string          { return yylval_token (TOK_STRING);      }
struct          { return yylval_token (TOK_STRUCT);      }
if              { return yylval_token (TOK_IF);          }
else            { return yylval_token (TOK_ELSE);        }
while           { return yylval_token (TOK_WHILE);       }
return          { return yylval_token (TOK_RETURN);      }
false           { return yylval_token (TOK_FALSE);       }
true            { return yylval_token (TOK_TRUE);        }
null            { return yylval_token (TOK_NULL);        }
ord             { return yylval_token (TOK_ORD);         }
chr             { return yylval_token (TOK_CHR);         }
new             { return yylval_token (TOK_NEW);         }
{NUMBER}        { return yylval_token (TOK_INTCON);      }
{CHAR}          { return yylval_token (TOK_CHARCON);     }
{BADCHAR}       { scanner_badtoken(yytext);            }
{STRING}        { return yylval_token (TOK_STRINGCON);   }
{BADSTRING}     { scanner_badtoken(yytext);              }
{IDENT}         { return yylval_token (TOK_IDENT);       }
{BADIDENT}      {scanner_badtoken(yytext);               }
[ \t]+          {                                        }
\n              { scanner_newline();                     }
.               { scanner_badchar (*yytext);             }

%%

RCSC("$Id: scanner.l,v 1.5 2015-04-16 17:17:51-07 - - $")

