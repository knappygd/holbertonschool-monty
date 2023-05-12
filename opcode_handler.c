#include "monty.h"

instruction_t* get_instructions() 
{
    /*static reserva memoria mientras dure el programa*/
    static instruction_t arr[] = {
        {"push", push},
        {"pall", pall},
        {"pop", pop},
        {"pint", pint},
        {"add", add},
        {"swap", swap},
        {"nop", nop},
        {NULL, NULL}
    };
    return arr;
}

int read_file(FILE *file)
{
    char *buffer = NULL, *token = NULL;
    stack_t *stack = NULL;
    size_t size = 0;
    unsigned int line_number = 0, i = 0, flag = 0;
    instruction_t *arr = get_instructions(); /*got the static array of functions ;)*/

    while (1)
    {
        if (getline(&buffer, &size, file) == -1) /*got the string of file inside buffer*/
        {
            free(buffer);
            break;
        }

        line_number++;
        flag = 0;
        i = 0;

        token  = strtok(buffer, " \t\n");
        if (token != NULL)
        {
            while (arr[i].opcode != NULL)
            {   /*compare the token with the code of array to get the function*/
                if (strcmp(token, arr[i].opcode) == 0)
                {   /*execute the function*/
                    arr[i].f(&stack, line_number);
                    flag = 1;/*if instruction exist change the flag to 1*/
                }
                i++;
            }
            /*if the instruction doesnt exists the flag is 0*/
            if (flag == 0)
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
                free(buffer), free_stack(stack), fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }
    free(buffer);
    free_stack(stack);
    return (0);
}