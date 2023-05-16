#include "monty.h"

/**
 * get_instructions - Holds an array containing the opcode and the functions.
 * Return: The corresponding array.
*/
instruction_t *get_instructions()
{
	static instruction_t arr[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
		{"sub", sub},
		{"div", dvs},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}};
	return (arr);
}
