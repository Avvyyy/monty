#include <stdio.h>
#include "monty.h"

stack_t **stack = NULL;

/**
 * main - Function to imlement the monty bytecode
 * @argc: Argumnent Count
 * @argv; Argumnet Vector
 *
 * Return: Integer represeting exit status
 */

int main(int argc, char *argv[])
{
	FILE *bytecode_file;
	char *bytecode_path;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	int n; // Variable to store the integer value for push

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		return (EXIT_FAILURE);
	}

	bytecode_path = argv[1];
	bytecode_file = fopen(bytecode_path, "r");
	if (bytecode_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", bytecode_path);
		return (EXIT_FAILURE);
	}

	while ((read = custom_getline(&line, &len, bytecode_file)) != -1)
	{
		line_number++;
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		if (line[0] != '\0')
		{
			if (strcmp(line, "push") == 0)
			{
				if (!is_number(line + 5))
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					free(line);
					free_stack(stack);
					fclose(bytecode_file);
					return (EXIT_FAILURE);
				}
				n = atoi(line + 5);
			}
			execute_opcode(stack, line, line_number, n);
		}
	}

	free(line);
	fclose(bytecode_file);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
