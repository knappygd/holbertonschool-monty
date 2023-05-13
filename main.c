#include "monty.h"

int main(int argc, char **argv)
{
    FILE *file;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /*argv[1] is the name of file to open. "r" readonly*/
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    read_file(file);

    fclose(file);
    return (0);
}
