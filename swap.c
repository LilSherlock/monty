#include "monty.h"
/**
 * swap - swap the two values of top
 * @stack: stack strucutre
 * @line_number: number of line
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int a = 0;
	int b = 0;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;

	(*stack)->n = b;
	(*stack)->next->n = a;
}
