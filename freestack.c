#include "monty.h"

/**
 * free_stack - frees the memory asigned to stack
 * @stack: pointer to the first node of stack
 * it walks the stack and frees the memory allocated to each node.
 * @stack is updated to point to the next node on each iteration
 */
void free_stack(stack_t *stack)
{
	stack_t *buffer; /*temporal pointer to take the actual stack value*/

	while (stack != NULL)
	{
		buffer = stack; /*copy the actual pointer of stack to the buffer*/
		stack = stack->next; /*update the node to the next*/
		free(buffer); /*free node*/
	}
}
