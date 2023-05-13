#include "monty.h"

/**
 * main - The entry function to run the program.
 * @argc: The number of arguments passed through the terminal.
 * @argv: An array holding the arguments passed through the terminal.
 *
 * Return: 0 if successful
*/
int main(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_file(file); /*magic is here*/

	fclose(file);
	return (0);
}
