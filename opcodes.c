#include "monty.h"

/**
 * push - Adds a new node to the stack with an int value.
 * @stack: Double pointer to the head of the stack
 * @line_number: The line on which the command is executed.
 * 
 * Return: 0 if successful
*/
int push(stack_t **stack, unsigned int line_number)
{
    if (!line_number)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

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

    return (0);
}

/**
 * pall - Prints the values of all the nodes in the stack.
 * @stack: Double pointer to the head of the stack.
 * 
 * Return: 0 if successful
*/
int pall(stack_t **stack)
{
    if (*stack == NULL)
    {
        exit(EXIT_FAILURE);
    }
        
    stack_t *current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }

    return (0);
}

/**
 * pop - Deletes the node at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line on which the command is executed.
 * 
 * Return: 0 if successful
*/
int pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;

    if (*stack)
        (*stack)->prev = NULL;
    free(temp);

    return (0);
}

/**
 * pint - Prints the value of the node at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line on which the command is executed.
 * 
 * Return: 0 if successful
*/
int pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);

    return (0);
}

/**
 * add - Adds the value of the two last nodes.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line on which the command is executed.
 * 
 * Return: 0 if successful
*/
int add(stack_t **stack, unsigned int line_number)
{
    int sum = 0, i = 0, nodes = 0;
    stack_t *current = *stack;

    if (!*stack)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    while (current)
    {
        nodes++;
        current = current->next;
    }

    if (nodes < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
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
