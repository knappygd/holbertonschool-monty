#include "monty.h"

int handle_opcode(char *line, int line_num)
{
    /* char *opcode[] = {"push", "pop", "pint", "pall", "swap", "add", "nop", NULL}; */
    char **line_contents;
    int flag = 0;

    line_contents = tokenizer(strdup(line), " ");

    if (strcmp(line_contents[0], "push") == 0)
    {
        if (isdigit(line_contents[1][0]))
            flag = 1;
        else
            exit(EXIT_FAILURE);
    }

    else if (strcmp(line_contents[0], "pop") == 0)
        flag = 2;
    else if (strcmp(line_contents[0], "pall") == 0)
        flag = 3;
    else if (strcmp(line_contents[0], "pint") == 0)
        flag = 4;
    else if (strcmp(line_contents[0], "add") == 0)
        flag = 5;

    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_num, line_contents[0]);
        exit(EXIT_FAILURE);
    }

    return (flag);
}


int read_file(char *file)
{
    char **tokens;
    char **line_contents;
    ssize_t op, rd;
    char *buffer;
    int letters = 1024, i = 0, ret;
    stack_t *stack = NULL;

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
        line_contents = tokenizer(strdup(tokens[i]), " ");

        ret = handle_opcode(tokens[i], i + 1);
        if (ret == 1)
            push(&stack, atoi(line_contents[1]));
        else if (ret == 2)
            pop(&stack);
        else if (ret == 3)
            pall(&stack);
        else if (ret == 4)
            pint(&stack);
        else if (ret == 5)
            add(&stack);
        i++;
    }

    free(buffer);

    return (0);
}