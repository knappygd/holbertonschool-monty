#include "monty.h"

/**/
/**/
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit (EXIT_FAILURE);
    }

    temp = (*stack)->next;

    if (temp->next != NULL)
    {
        (*stack)->next = temp->next;
        (*stack)->next->prev = *stack;
    }
    else
    {
        temp->prev->prev = temp;
        temp->prev->next = NULL;
    }
    
    temp->prev = NULL;
    temp->next = *stack;
    (*stack) = temp;
}

void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}