#include "monty.h"
/**
 * jutsu_liberacion - free memory
 *
 * Return: nothing
*/
void jutsu_liberacion(void)
{
	free(free_Mmry.tmp);
	free(free_Mmry.line);
	fclose(free_Mmry.fp);
}

/**
 * kai - free memory
 *
 * @stack: stack
 *
 * Return: nothing
*/
void kai(stack_t **stack)
{
	stack_t *vector;

	while ((*stack) != NULL)
	{
		vector = (*stack);
		(*stack) = (*stack)->next;
		free(vector);
	}
	free((*stack));
}
