#include "monty.h"
/**
 * s_stack - sets the format of the data to a stack (LIFO)
 * @stack:pointer to head
 * @line_number: num line
 */

void s_stack(stack_t **stack, unsigned int line_number)
{
	if (stack || line_number)
		global.flag = 1;
}
