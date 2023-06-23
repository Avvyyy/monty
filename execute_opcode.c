#include "monty.h"

/* Define an array of instructions */
instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{NULL, NULL} /* Last element of the array should be NULL for termination */
};

/**
 * execute_opcode - Execute the corresponding opcode function based on input
 * @stack: Double pointer to the stack
 * @opcode: The opcode to execute
 * @line_number: The current line number in the bytecode file
 * @n: The integer value (optional parameter for push function)
 */
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number, int n)
{
	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			if (instructions[i].f == push)
				instructions[i].f(stack, line_number, n); // Pass n parameter to push function
			else
				instructions[i].f(stack, line_number); // Call other functions without passing n
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

