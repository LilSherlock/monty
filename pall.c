#include "monty.h"
/**
 * pall - print stack
 *
 * @stack: stack
 * @line_number: number of lines
 *
 * Return: nothing
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *print_stack = *stack;

	if (stack == NULL || *stack == NULL)
		return;
	(void)line_number;
	while (print_stack != NULL)
	{
		printf("%d\n", print_stack->n);
		print_stack = print_stack->next;
	}
}
