#include "monty.h"

instruction_t* get_instructions() 
{
    /*static reserva memoria mientras dure el programa*/
    static instruction_t arr[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };
    return arr;
}

int read_file(FILE *file)
{
    char *buffer = NULL, *token = NULL;
    stack_t *stack = NULL;
    int i = 0, flag = 0;
    size_t size = 0;
    unsigned int line_number = 0;
    instruction_t *arr = get_instructions();

    while (1)
    {
        if (getline(&buffer, &size, file) == -1)
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
            {
                if (strcmp(token, arr[i].opcode) == 0)
                {
                    arr[i].f(&stack, line_number); /*aca busca la funcion correspondiente en el arreglo*/
                    flag = 1; /*instruccion encontrada*/
                }
                i++;
            }
            /*si la instruccion no existe*/
            if (flag == 0)
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
                free_stack(stack), free(buffer), fclose(file);
                 exit(EXIT_FAILURE);
            }
        }
    }
    free_stack(stack);
    return (0);
}