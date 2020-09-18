#include "monty.h"
/**
 * add - add the two last elements
 *
 * @stack: stack
 * @line_number: - number of line
 *
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	int a = 0;
	int b = 0;
	int temp = 0;

	if (stack_length(stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;

	temp = a + b;
	pop(stack, line_number);
	(*stack)->n = temp;
}
