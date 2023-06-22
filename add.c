#include "monty.h"
#include <stdlib.h>

/**
 *add - Function to add the first 2 elements in a stack
 *@stack: Pointer to top of stack
 *@line_number: LIne number of add function
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL || top->next == NULL) {
 		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top->next->n += top->n;
	pop(stack, line_number);
}

