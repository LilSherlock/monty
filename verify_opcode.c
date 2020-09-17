#include "monty.h"

void verify(char *line, unsigned int line_number, stack_t **stack)
{
    char *token = NULL, *token_value = NULL;

    token = strtok(line, DELIMITERS);

    if (strcmp(token, "push") == 0)
    {
        token_value = strtok(NULL, DELIMITERS);
        push(line_number, stack, token_value);
    }
    else
    {
        opcode_selector(token, stack, line_number);
    }
}

int opcode_selector(char *token, stack_t **stack, unsigned int line_number)
{
    int i = 0;

    instruction_t opcodes[] = {
        {"pall", pall},
        {NULL, NULL}
    };
    while (opcodes[i].opcode != NULL)
    {
        if (strcmp(opcodes[i].opcode, token) == 0)
        {
            (opcodes[i].f)(stack, line_number);
            return (EXIT_SUCCESS);
        }
        i++;
    }
    printf("L%d: unknown instruction %s\n", line_number, token);
	exit(EXIT_FAILURE);
}

void push(unsigned int line_number, stack_t **stack, char *token_value)
{
    stack_t *new = NULL;

    if (token_value == NULL)
    {
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
    }
    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new->n = atoi(token_value);
    new->prev = NULL;
    new->next = NULL;
    if (*stack != NULL )
    {
        new->next = *stack;
        (*stack)->prev = new;
    }
    *stack = new;
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *print_stack = *stack;

	if (stack == NULL || *stack == NULL)
		return;
    
    while(print_stack != NULL)
    {
        printf("%d\n", print_stack->n);
        print_stack = print_stack->next;
    }
}
