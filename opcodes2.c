#include "monty.h"

/**
 * swap - Swap the last two nodes from the stack.
 * @stack: Pointer to the head node.
 * @line_number: Line number where the instruction is.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
}

/**
 * nop - Does literally nothing.
 * @stack: Unused.
 * @line_number: Unused.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - Subtracts the value of the two last nodes.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line on which the command is executed.
*/
void sub(stack_t **stack, unsigned int line_number)
{

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div - Divides the value of the two last nodes.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line on which the command is executed.
*/
void dvs(stack_t **stack, unsigned int line_number)
{

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n = 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}