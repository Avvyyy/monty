#include "monty.h"
/**
 * s_rotr - rotates the stack to the bottom
 * @stack: pointer to head
 * @line_number: current num line
 */

void s_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp2;

	if (*stack && (*stack)->next)
	{
		temp2 = *stack;
		if (line_number)
			while (temp2->next)
			{
				temp2 = temp2->next;
			}
		temp2->next = *stack;
		temp2->prev->next = NULL;
		temp2->prev = NULL;
		*stack = temp2;
	}
}
