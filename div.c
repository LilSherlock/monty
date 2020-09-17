#include "monty.h"
/**
 * divi - arithmetic operation
 *
 * @stack: stack
 * @line_number: number of line
 *
 * Return: nothing
*/
void divi(stack_t **stack, unsigned int line_number)
{
	stack_t *vector;
	int x = 0;

	vector = *stack;
	if ((*stack) == NULL || vector == NULL || (*stack)->next == NULL)
	{
		jutsu_liberacion();
		kai(stack);
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	x = vector->n;
	if (x == 0)
	{
		jutsu_liberacion();
		kai(stack);
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	(*stack)->n = (*stack)->n / x;
	free(vector);
}
