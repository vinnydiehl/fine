#include "main.h"

int main(int argc, char* argv[])
{
    if (argc == 1)
        interactive(); // No arguments, enter interactive mode

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
