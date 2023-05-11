#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char *push_val;

int read_file(char *file);
char **tokenizer(char *input, char *delim);
int handle_opcode(char *line, int line_num);
int push(stack_t **stack, unsigned int line_number);
int pall(stack_t **stack);
int pop(stack_t **stack, unsigned int line_number);
int pint(stack_t **stack, unsigned int line_number);
int add(stack_t **stack, unsigned int line_number);
int space_input(char *input);
int swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void free_list(stack_t **stack);

#endif