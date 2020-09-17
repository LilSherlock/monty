#include "monty.h"
/**
 * push - add to stack
 *
 * @stack: stack
 * @line_number: number of lines
 *
 * Return: nothing
*/
void push(stack_t **stack, unsigned int line_number)
{
	char *token_v;
	stack_t *new = NULL;
	int ite = 0;

	token_v = strtok(free_Mmry.line, DELIMITERS);
	if (token_v == NULL)
		return;
	token_v = strtok(NULL, DELIMITERS);
	if (token_v == NULL)
	{
		jutsu_liberacion();
		kai(stack);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (token_v[ite] != '\0')
	{
		if ((token_v[ite] < '0' || token_v[ite] > '9') && token_v[ite] != '-')
		{
			jutsu_liberacion();
			kai(stack);
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		ite++;
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(token_v);
	new->prev = NULL;
	new->next = NULL;
	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new; }
