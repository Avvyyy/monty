#include <stdlib.h>
#include "monty.h"

/**
 * push - Function to add new data to the top of the stack
 * @stack: Pointer to top of the stack
 * @line_number: Line number of the instruction
 * @n: The integer value to push
 */
void push(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
	(void)line_number;
}
