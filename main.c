#include "monty.h"

/**
 * main ->
 */

int main(int argc, char *argv[])
{
	char* filepath = argv[1];
	char *line = NULL;
	void *pointer = malloc(1);
	FILE *file = fopen(filepath, "r");
	int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit (EXIT_FAILURE);
	}
	/* open file for reading*/
	if (file == NULL)
		{
			fprintf(stderr, "Error: can't open file %s\n", filepath);
			exit (EXIT_FAILURE);
		}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		fprintf(stderr, "L<line_number>: unknown instruction <opcode>%d\n", line_number);
		exit (EXIT_FAILURE);
		line_number++;
	}
	fclose(file);

	if (pointer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit (EXIT_FAILURE);
	}
	free(pointer);
	return (0);
}

