#include "interactive.h"

void
interactive(void)
{
	/* Run Interactive Fine. */

	while (1) {
		printf(">>> ");
		char *input = readline();

		if (strcmp(input, "quit\n") == 0)
			break;

		parse_sexp(input);
		printf("\n");
	}
}

char*
readline(void)
{
	/* Read in a line from stdin. */

	char *line = malloc(100), *linep = line;
	size_t lenmax = 100, len = lenmax;
	int c;

	if (line == NULL)
		return NULL;

	while (1) {
		c = fgetc(stdin);
		if (c == EOF)
			break;

		if (--len == 0) {
			char *linen = realloc(linep, lenmax *= 2);
			len = lenmax;

			if (linen == NULL) {
				free(linep);
				return NULL;
			}
			line = linen + (line - linep);
			linep = linen;
		}

		if ((*line++ = c) == '\n')
			break;
	}

	*line = '\0';
	return linep;
}

