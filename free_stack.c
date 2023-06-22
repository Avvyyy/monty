#include "monty.h"

/**
 * free_stack - Frees all nodes in the stack
 */
void free_stack(void)
{
	stack_t *current = *stack;
	stack_t *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}

	*stack = NULL;
}
