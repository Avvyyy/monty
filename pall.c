#include <stdio.h>
#include "monty.h"

/**
 * pall - Function prints all the values on the stack,
 *  starting from the top of the stack.
 * @stack: Pointer to top of stack
 * @line_number: line number of function in file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

	(void)line_number; /* Unused parameter */
}
