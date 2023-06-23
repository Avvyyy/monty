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
 */
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number)
{
	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
