#include "monty.h"
/**
 * s_pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: head
 * @line_number: current line number
 */
void s_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
		return;
	if (line_number)
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
}
