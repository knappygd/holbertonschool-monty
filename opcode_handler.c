#include "monty.h"

/**
 * get_instructions - Holds an array containing the opcode and the functions.
 *
 * Return: The corresponding array.
*/
instruction_t *get_instructions()
{
	/*static reserva memoria mientras dure el programa*/
	static instruction_t arr[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}};
	return (arr);
}

/**
 * read_file - Handles the content of the file passed.
 * @file: The file (of type FILE *) previously read in main().
 *
 * Return: 0 if successful
*/
int read_file(FILE *file)
{
	char *buffer = NULL, *token = NULL;
	stack_t *stack = NULL;
	size_t size = 0;
	unsigned int line_number = 0, i = 0, flag = 0;
	instruction_t *arr = get_instructions();

	while (1)
	{
		if (getline(&buffer, &size, file) == -1)
		{
			free(buffer);
			break;
		}

		line_number++;
		flag = 0;
		token = strtok(buffer, " \t\n");
		if (token != NULL)
		{
			for (i = 0; arr[i].opcode != NULL; i++)
			{
				if (strcmp(token, arr[i].opcode) == 0)
				{
					flag = 1;
					arr[i].f(&stack, line_number);
				}
			}
			if (flag == 0)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
				free(buffer), free_stack(stack), fclose(file);
				exit(EXIT_FAILURE);
			}
		}
	}
	free_stack(stack);
	return (0);
}
