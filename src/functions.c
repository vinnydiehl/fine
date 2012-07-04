#include "functions.h"

void
fine_print(int argc, char* argv[])
{
	int i;
	for (i = 1; i <= argc; ++i)
		printf("%s", argv[i]);
	evaluation[0] = 0;
}

void
fine_add(int argc, char* argv[])
{
	int i, result = 0;
	for (i = 1; i <= argc; ++i)
		result += atoi(argv[i]);
	sprintf(evaluation, "%d", result);
}

void
fine_sub(int argc, char* argv[])
{
	int i, result = atoi(argv[1]);
	for (i = 2; i <= argc; ++i)
		result -= atoi(argv[i]);
	sprintf(evaluation, "%d", result);
}

void
fine_mul(int argc, char* argv[])
{
	int i, result = 1;
	for (i = 1; i <= argc; ++i)
		result *= atoi(argv[i]);
	sprintf(evaluation, "%d", result);
}

void
fine_div(int argc, char* argv[])
{
	int i, result = atoi(argv[1]);
	for (i = 2; i <= argc; ++i)
		result /= atoi(argv[i]);
	sprintf(evaluation, "%d", result);
}

// Tokenize a list of the form (func arg...), using any whitespace to delimit
// separate components, and pass them to the matching inbuilt function.

// TODO: Properly handle strings, implement a hash for the function map.
char*
eval(char* list)
{
	static char* funcs[] = {"print", "+", "-", "*", "/"};
	static function calls[] = {fine_print, fine_add, fine_sub, fine_mul, fine_div};
	const int func_total = sizeof(funcs) / sizeof(funcs[0]);

	++list; // Skip over the opening parenthesis.
	int i = 0, j;
	char* tokens[16]; // arbitrary but seemingly reasonable token limit

	for (;; list = NULL)
		if ((tokens[i++] = strtok(list, " \n\t")) == NULL)
			break;

	i -= 2;
	tokens[i][strlen(tokens[i]) - 1] = 0; // Disregard the closing parenthesis.
	for (j = 0; j < func_total; ++j)
		if (strcmp(tokens[0], funcs[j]) == 0)
			calls[j](i, tokens);
	return evaluation;
}

