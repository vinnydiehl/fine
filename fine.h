#include <ctype.h>
#include <errno.h>
#include <error.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* filestr(FILE*);
void  parse_sexp(char*);
char* eval(char*);
void  debug(char*, regmatch_t, char*);

typedef void (*function)();

// TODO: Consider whether or not it's a good idea to have the latest evaluation
// stored as a global string.
// HINT: Probably not.
char evaluation[128];

#include "fine_functions.c"
