#include "monty.h"
/**
 * opcode_selector - select an option
 *
 * @stack: stack
 * @line_number: number of lines
 *
 * Return: nothing
*/
void opcode_selector(stack_t **stack, unsigned int line_number)
{
	char *token = strdup(free_Mmry.line);
	int target = 0, ite = 0;

	instruction_t op[] = {{"push", push}, {"pint", pint}, {"pall", pall},
	{"pop", pop}, {"swap", swap}, {"nop", nop}, {"sub", sub}, {"div", divi},
	{"mul", mul}, {"mod", mod},
	{NULL, NULL}
	};
	free_Mmry.tmp = token;
	token = strtok(token, DELIMITERS);
	if (token == NULL)
	{
		free(free_Mmry.tmp);
		return;
	}
	else if (token[0] != '\0' && token[0] == '#')
	{
		free(free_Mmry.tmp);
		return;
	}
	while (op[ite].opcode != NULL) /*structrure elements iterator*/
	{
		if (strcmp(token, op[ite].opcode) == 0)
		{
			target = 1;
			(op[ite].f)(stack, line_number);
			break;
		}
		ite++;
	}
	if (target == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
		jutsu_liberacion();
		kai(stack);
		exit(EXIT_FAILURE);
	}
	free(free_Mmry.tmp);
}
