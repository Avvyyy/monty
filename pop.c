#include <stdlib.h>
#include "monty.h"

/**
 * pop - Function that removes the top element of the stack.
 *@stack: Pointer to top of stack
 *@line_number: LIne number of start of opcode function
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
