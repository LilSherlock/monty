#include "monty.h"
/**
 * pint - print top of the stack
 * @stack: stack structure
 * @line_number: number of line
 */
void pint(stack_t **stack, unsigned int line_number)
{
	int j = 0;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	j = (*stack)->n;
	printf("%d\n", j);
}
