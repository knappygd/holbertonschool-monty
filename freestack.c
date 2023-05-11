#include "monty.h"

void free_stack(stack_t **stack)
{
	stack_t *buffer;

	while (*stack)
	{
		buffer = (*stack)->next;
		free(*stack);
		(*stack) = buffer;
	}
}