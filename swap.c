#include <stdio.h>
#include "monty.h"

/**
 * swap- Function that swaps the top two elements of the stack.
 * @stack: Pointer to top of the stack
 * @line_number: Line number of the swap function
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = top->next;

	top->prev = next;
	top->next = next->next;

	if (next->next != NULL)
		next->next->prev = top;

	next->prev = NULL;
	next->next = top;

	*stack = next;
}
