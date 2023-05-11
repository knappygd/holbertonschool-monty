#include "monty.h"
/**/
/**/
int swap(stack_t **stack)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "Error: can't swap, stack too short.\n");
        exit (EXIT_FAILURE);
    }

    temp = (*stack)->next
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
    
    return (0);
}