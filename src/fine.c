#include "fine.h"

// Return a string containing the full contents of the specified FILE.
char*
filestr(FILE *file)
{
	fseek(file, 0, SEEK_END);
	int filesize = ftell(file);
	rewind(file);

	char* data = malloc(filesize + 1);
	int bytes_read = fread(data, 1, filesize, file);
	if (bytes_read != filesize)
		error(1, 0, "Incomplete file read");

	data[filesize] = 0; // Your happiness is my happiness, Valgrind.
	fclose(file);
	return data;
}

void
parse_sexp(char *src)
{
	int i, j, len, eval_len, so, eo;
	char* list;
	regex_t list_re;
	regmatch_t match[1];
	// Find the first occurrence of a non-nested list.
	regcomp(&list_re, "\\([^()]+\\)", REG_EXTENDED);

	while (regexec(&list_re, src, 1, match, 0) != REG_NOMATCH) {
		so = match[0].rm_so;
		eo = match[0].rm_eo;
		len = eo - so;

		list = malloc(len + 1);
		memcpy(list, src + so, len);
		list[len] = 0;

		// eval() currently modifies the list in place for the sake of efficiency
		// but this interferes with reporting, so duplicate it when debugging.
#if DEBUG
		eval(strdup(list));
#else
		eval(list);
#endif

		eval_len = strlen(evaluation);

#if DEBUG
		debug(src, match[0], list);
#endif

		// Iterate over the characters of the list, replacing each of them with
		// the matching character in the evaluation. When no more characters are
		// available from the latter, switch to spaces so as to "clear" the list
		// and prevent it from being processed again.

		// TODO: Make this significantly less hacky; at present, the evaluation
		// string must be shorter than the list it replaces, which is very bad.
		for (i = so, j = 0; i < eo; ++i, ++j)
			src[i] = j < eval_len ? evaluation[j] : ' ';

		free(list);
	}

	regfree(&list_re);
}

void
debug(char* sexp, regmatch_t match, char* list)
{
	int i, list_len = strlen(list);
	char prev = 0;
	printf("\ncurrent s-expression:\n%s\nlist ", sexp);
	for (i = 0; i < list_len; ++i) {
		if (!isspace(list[i]) || !isspace(prev))
			putchar(isspace(list[i]) ? ' ' : list[i]);
		prev = list[i];
	}
	printf(" found at [%d-%d] evaluated to %s\n---", match.rm_so, match.rm_eo, evaluation);


	// "%s\nlist %s found at %d-%d\nevaluated to %s\n---\n",
	// 	src, list, match.rm_so, match.rm_eo, evaluation);
}

