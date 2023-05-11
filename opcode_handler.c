#include "monty.h"

char *push_val;

/**
 * handle_opcode - Assigns a flag value depending on the command from the file.
 * @line: A line from the file to work with.
 * @line_num: The line number.
 * 
 * Return: The flag.
*/
int handle_opcode(char *line, int line_num)
{
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
    else if (strcmp(line_contents[0], "swap") == 0)
        flag = 6;
    else if (strcmp(line_contents[0], "nop") == 0)
        flag = 7;

    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_num, line_contents[0]);
        exit(EXIT_FAILURE);
    }

    return (flag);
}

/**
 * read_file - Reads the content of the file passed and tokenizes the content.
 * @file: The file to read from.
 * 
 * Return: 0 if successful
*/
int read_file(char *file)
{
    char **tokens;
    char **line_contents;
    ssize_t op, rd;
    char *buffer;
    int letters = 1024, i = 0, ret, j = 0;
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
        if (space_input(tokens[i]) > 0)
        {
            i++;
            continue;
        }

        line_contents = tokenizer(strdup(tokens[i]), " ");

        ret = handle_opcode(tokens[i], i + 1);
        if (ret == 1)
        {
            if (!line_contents[1])
            {
                fprintf(stderr, "L%d: usage: push integer\n", i + 1);
                exit(EXIT_FAILURE);
            }

            push_val = line_contents[1];

            while (push_val[j])
            {
                if (!isdigit(push_val[j]))
                {
                    fprintf(stderr, "L%d: usage: push integer\n", i + 1);
                    exit(EXIT_FAILURE);
                }
                j++;
            }
            push(&stack, i + 1);
        }
        else if (ret == 2)
            pop(&stack, i + 1);
        else if (ret == 3)
            pall(&stack);
        else if (ret == 4)
            pint(&stack, i + 1);
        else if (ret == 5)
            add(&stack, i + 1);
        else if (ret == 6)
            swap(&stack, i + 1);
        else if (ret == 7)
            nop(&stack, i + 1);
        i++;
    }

    free(buffer);

    return (0);
}

/**
 * space_input - Checker function to handle space-char-only lines (blanks).
 * @input: The line to check.
 * 
 * Return: 0 if there is a command, or a positive number if it's a blank line.
*/
int space_input(char *input)
{
	int i, in_len = strlen(input);

	for (i = 0; i < in_len; i++)
	{
		if (input[i] != ' ')
		{
			if (input[i] == 10)
				break;
			i = 0;
			break;
		}
	}

	return (i);
}