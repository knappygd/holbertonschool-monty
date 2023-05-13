#include "monty.h"
/**
 * get_instructions - Holds an array containing the opcode and the functions.
 * Return: The corresponding array.
*/
instruction_t *get_instructions()
{
	/*static reserves memory while the program is active*/
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