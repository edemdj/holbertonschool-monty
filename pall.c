#include "monty.h"

/**
 * pall - removes the top element of the stack
 * @stack: the stack
 * @line_number: current line number of the bytecode file
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)(line_number);
	
	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		stack = &(*stack)->next;
	}
}
