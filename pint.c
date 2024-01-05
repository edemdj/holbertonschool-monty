#include "monty.h"
/**
 * pint -  prints the value at the top of the stack
 * @stack: the stack
 * @line_number: current line number of the bytecode file
 *
 * Return: Nothing
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		dprintf(2, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
