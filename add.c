#include "monty.h"
/**
 * add - adds the top two elements of the stack
 *  @stack: the stack
 * @line_number: current line number of the bytecode file
 * @n:integer
 * Return: Nothing
*/
void _add(stack_t **stack, unsigned int line_number)
{
	
	int n = 0;

    if (!*stack || !(*stack)->next)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

    n += (*stack)->n;
	op_pop(stack, line_number);
	(*stack)->n += n;

}
