#include "monty.h"

/**
 * push - Adds a new node to the stack with an int value.
 * @stack: Double pointer to the head of the stack
 * @line_number: The line on which the command is executed.
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node = NULL;
    char *token = NULL;
    int n_push = 0, i = 0;

    new_node = malloc(sizeof(stack_t)); /*creating node for work*/
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        if (*stack != NULL)
            free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    token = strtok(NULL, " \t\n");         /*continue static tokenization from read_file*/
    if (token == NULL) /*check if is a digit or maybe it will be a segmentation fault*/
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        free(new_node), free_stack(*stack), exit(EXIT_FAILURE); /*free all before exit*/
    }

    while (token[i] && token[0] != '-')
    {
        if (!isdigit(token[i]))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            free(new_node), free_stack(*stack), exit(EXIT_FAILURE);
        }
        i++;
    }

    n_push = atoi(token);

    /*loading stack*/
    new_node->n = n_push;
    new_node->prev = NULL;

    if (*stack == NULL)
    {
        new_node->next = NULL;
        *stack = new_node;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
        *stack = new_node;
    }
}

/**
 * pall - Prints the values of all the nodes in the stack.
 * @stack: Double pointer to the head of the stack.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    (void) line_number;
    stack_t *current = *stack;

    if (*stack == NULL)
            return;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * pop - Deletes the node at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line on which the command is executed.
*/
void pop(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->next == NULL)
    {
        free(*stack);
        *stack = NULL;
    }
    else
    {
        *stack = (*stack)->next;
        free((*stack)->prev);
        (*stack)->prev = NULL;
    }
}

/**
 * pint - Prints the value of the node at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line on which the command is executed.
*/
void pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * add - Adds the value of the two last nodes.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line on which the command is executed.
*/
void add(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;

}
