#include "monty.h"

/**
 * swap - swap two elements from top of the stack
 * @stack: head node
 * @line_number: line number where the instruction is
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        free_stack(*stack);
        exit (EXIT_FAILURE);
    }
    else
    {
        /*swaps the n value from the first two elements of stack*/
        temp = (*stack)->n;
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = temp;
    }
}

/**
 * nop - nothing here
 * @stack: unused
 * @line_number: unused
*/
void nop(stack_t **stack, unsigned int line_number)
{
    (void) stack;
    (void) line_number;
}

