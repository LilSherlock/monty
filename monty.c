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
	size_t len = 0;
	ssize_t line_size;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	free_Mmry.fp = fopen(filename, "r");
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!free_Mmry.fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line_size = getline(&free_Mmry.line, &len, free_Mmry.fp);
	while (line_size >= 0)
	{
		line_number++;
		opcode_selector(&stack, line_number);
		line_size = getline(&free_Mmry.line, &len, free_Mmry.fp);
	}
	free(free_Mmry.line);
	kai(&stack);
	fclose(free_Mmry.fp);
	return (EXIT_SUCCESS);
}
