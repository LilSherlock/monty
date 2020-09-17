#include "monty.h"

int main(int argc, char **argv)
{
    char *filename = argv[1];
    char *line = NULL, *token = NULL, *value = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    ssize_t line_size;
    FILE *fp;

    fp = fopen(filename, "r");
    if (!filename)
    {
        fprintf(stderr, "USAGE: monty file\n");
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
        token = strtok(line, DELIMITERS);
        value = strtok(NULL, DELIMITERS);
        printf("%s %s\n", line, value);
        line_size = getline(&line, &len, fp);
    }
    free(line);
    line = NULL;
    fclose(fp);
    return (0);
}
