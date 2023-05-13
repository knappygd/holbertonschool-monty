#include "monty.h"
/**
 * free_stack - Frees the memory asigned to stack
 * @stack: Pointer to the first node of stack
 */
void free_stack(stack_t *stack)
{
	stack_t *buffer;

	while (stack)
	{
		buffer = stack;
		stack = stack->next;
		free(buffer);
	}
}
