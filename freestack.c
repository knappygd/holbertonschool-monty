#include "monty.h"

void free_stack(stack_t *stack)
{
	stack_t *buffer;

	while (stack != NULL)
	{
		buffer = stack;
		stack = stack->next;
		free(buffer);
	}
}