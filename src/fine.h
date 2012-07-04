#ifndef FINE_H_INCLUDED
#define FINE_H_INCLUDED

#include <ctype.h>
#include <error.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

#include "globals.h"

char* filestr(FILE*);
void parse_sexp(char*);
void debug(char*, regmatch_t, char*);

#endif // FINE_H_INCLUDED

