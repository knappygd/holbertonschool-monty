#include "monty.h"

int main(void)
{
    stack_t *stack = NULL;
    /* char *file;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = argv[1];

    read_file(file); */

    push(&stack, 5);
    push(&stack, 7);
    push(&stack, 1);
    push(&stack, 3);
    pall(&stack);
    pop(&stack);
    pall(&stack);

    return (0);    
}