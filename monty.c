#include "monty.h"

int main(int argc, char **argv)
{
	char *filename = argv[1];
	char *line = NULL, *opcode = NULL, *value = NULL;
	size_t len = 0;
	ssize_t line_size;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	FILE *fp;

	fp = fopen(filename, "r");
	if (!filename)
	{
		fprintf(stderr, "USAGE: mchar *line_numberonty file\n");
		return (EXIT_FAILURE);
	}
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}
	line_size = getline(&line, &len, fp);
	while (line_size >= 0)
	{
		line_number++;
		verify(line, line_number, &stack);
		line_size = getline(&line, &len, fp);
	}
	free(line);
	line = NULL;
	fclose(fp);
	return (EXIT_SUCCESS);
}
