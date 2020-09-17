#include "monty.h"
/**
 * stack_length - returns length of stack
 * @stack: pointer to head of stack
 * Return: length of stack
 */
size_t stack_length(stack_t **stack)
{
	stack_t *current;
	unsigned int n = 0;

	current = *stack;
	while (current != NULL)
	{
		current = current->next;
		n++;
	}

	return (n);
}
/**
 * swap - swap the two values of top
 * @stack: stack strucutre
 * @line_number: number of line
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int a = 0;
	int b = 0;

	if (stack_length(stack) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;

	(*stack)->n = b;
	(*stack)->next->n = a;
}
