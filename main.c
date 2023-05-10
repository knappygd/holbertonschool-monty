#include "monty.h"

int main(int argc, char **argv)
{
    /* stack_t *stack = NULL; */
    char *file;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* (void)argv;
    (void)argc; */

    file = argv[1];

    read_file(file);

    /* push(&stack, 2);
    push(&stack, 9);
    push(&stack, 5);
    push(&stack, 0);
    printf("pall:\n");
    pall(&stack);
    printf("(pop below)\n");
    pop(&stack);
    printf("pall:\n");
    pall(&stack);
    printf("pint:\n");
    pint(&stack);
    printf("add:\n");
    add(&stack);
    pall(&stack); */

    return (0);    
}