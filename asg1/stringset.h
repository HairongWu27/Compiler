// $Id: stringset.h,v 1.1 2015/04/07 04:39:51 hwu27 Exp $

#ifndef __STRINGSET__
#define __STRINGSET__

#include <string>

#include <stdio.h>

const std::string* intern_stringset (const char*);

void dump_stringset (FILE*);

#endif

