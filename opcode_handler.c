#include "monty.h"

int handle_opcode(char *line)
{
    char *opcode[] = {"push", "pop", "pint", "pall", "swap", "add", "nop", NULL};
    char **line_contents;
    int i;
    stack_t *stack = NULL;

    line_contents = tokenizer(line, " ");

    for (i = 0; opcode[i]; i++)
    {
        if (strcmp(opcode[i], line_contents[0]) == 0)
        {
            if (i == 0)
            {
                push(&stack, atoi(line_contents[1]));
            }

            if (i == 3)
            {
                pall(&stack);
            }
        }
    }

    return (0);
}


int read_file(char *file)
{
    char **tokens;
    ssize_t op, rd;
    char *buffer;
    int letters = 1024, i = 0;

    buffer = malloc(sizeof(char) * letters);

    op = open(file, O_RDWR);
    if (op == -1)
    {
        free(buffer);
        return (0);
    }
    rd = read(op, buffer, letters);
    if (rd == -1)
    {
        free(buffer);
        return (0);
    }

    tokens = tokenizer(buffer, "\n");

    while (tokens[i])
    {
        handle_opcode(tokens[i]);
        i++;
    }

    free(buffer);

    return (0);
}