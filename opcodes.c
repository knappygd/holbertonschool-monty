#include "monty.h"

int push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = line_number;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;

    printf("Added node with value %d\n", new_node->n);

    return (0);
}

int pall(stack_t **stack)
{
    stack_t *current = *stack;
    int nodes = 0;

    printf("Stack:\n");
    while (current != NULL)
    {
        printf("%d\n", current->n);
        nodes++;
        current = current->next;
    }

    return nodes;
}

int pop(stack_t **stack)
{
    stack_t *temp;

    if (*stack == NULL) {
        fprintf(stderr, "Error: stack is empty.\n");
        return 0;
    }

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(temp);

    return (0);
}


