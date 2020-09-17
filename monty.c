#include "monty.h"

carry free_Mmry;
/**
 * main - select an option
 *
 * @argc: stack
 * @argv: number of lines
 *
 * Return: 0 or 1
*/
int main(int argc, char **argv)
{
	char *filename = argv[1];
	size_t line_size = 300;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	free_Mmry.line = malloc(line_size * sizeof(char));
	if (free_Mmry.line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	(void)argc;
	free_Mmry.fp = fopen(filename, "r");
	if (!filename)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!free_Mmry.fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&free_Mmry.line, &line_size, free_Mmry.fp)
	!= -1)
	{
		line_number++;
		opcode_selector(&stack, line_number);
	}
	free(free_Mmry.line);
	kai(&stack);
	fclose(free_Mmry.fp);
	return (EXIT_SUCCESS);
}
