#include "monty.h"

instruction_t instructions[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},
    {"swap", swap},
    {"add", add},
    {"nop", nop},
    {NULL, NULL}
};

/**
 * push - Function to add new data to the top of the stack
 * @stack: Pointer to top of the stack
 * @line_number: Line number of the instruction
 * @n: The integer value to push
 */

void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number, int n)
{
    int i = 0;

    while (instructions[i].opcode != NULL)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            if (instructions[i].f == push)
                instructions[i].f(stack, n, line_number);
            else
                instructions[i].f(stack, line_number);
            return;
        }
        i++;
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    free_stack(stack);
    exit(EXIT_FAILURE);
}
