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

    if (!*stack)
        printf("empty\n");

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }

    return (0);
}

int pop(stack_t **stack)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L<line_number>: can't pop an empty stack\n");
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;

    if (*stack)
        (*stack)->prev = NULL;
    free(temp);

    return (0);
}

int pint(stack_t **stack)
{
    if (!*stack)
    {
        fprintf(stderr, "L<line_number>: can't pint, stack empty\n");
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);

    return (0);
}

int add(stack_t **stack)
{
    int sum = 0, i = 0, nodes = 0;
    stack_t *current = *stack;

    if (!*stack)
        return (0);

    while (current)
    {
        nodes++;
        current = current->next;
    }

    if (nodes < 2)
    {
        fprintf(stderr, "L<line_number>: can't add, stack too short\n");
        exit(EXIT_FAILURE);
    }

    while (i < 2)
	{
		sum += (*stack)->n;
		*stack = (*stack)->next;
        i++;
	}

    printf("%d\n", sum);

	return (0);
}
