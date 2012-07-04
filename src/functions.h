#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "globals.h"

void fine_print(int argc, char* argv[]);
void fine_add(int argc, char* argv[]);
void fine_sub(int argc, char* argv[]);
void fine_mul(int argc, char* argv[]);
void fine_div(int argc, char* argv[]);

char* eval(char* list);

typedef void (*function)();

#endif // FUNCTIONS_H_INCLUDED

