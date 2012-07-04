#include "app.h"

int
main(int argc, char* argv[])
{
	if (argc == 1)
		error(1, 0, "No input files");

	FILE *src_file = fopen(argv[1], "r");
	if (errno)
		error(errno, 0, "%s", strerror(errno));

	char* src = filestr(src_file);
	parse_sexp(src);
	free(src);

	// Needs a newline before the program terminates
	printf("\n");

	return 0;
}

