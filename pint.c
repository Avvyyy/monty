#include <stdio.h>
#include "monty.h"

/**
 * pint- Function that prints the value at the top of the stack,
 * followed by a new line.
 * @stack: Pointer to top of stack
 * @line_number:line number where the opcode is encountered
 * in the Monty byte code file.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
