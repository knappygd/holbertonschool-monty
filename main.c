#include "monty.h"

int main(int argc, char **argv)
{
    char *file;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = argv[1];

    read_file(file);

    return (0);    
}
