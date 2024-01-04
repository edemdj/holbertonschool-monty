#include "monty.h"

void detect_command(char *command, stack_t **stack, unsigned int line_number)
{
    size_t i;
	instruction_t opcodes[] = {
		{"push", op_push},
		{"pall", pall},
		{"pint", pint},
		{"pop", op_pop},
        {"swap", op_swap},
		{NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, command) == 0)
		{
			opcodes[i].f(stack, line_number);
			return;
		}
	}

	dprintf(1,
		"L%u: unknown instruction %s\n",
		line_number, command);
	exit(EXIT_FAILURE);
}
