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
	stack_t *head;

	head = *stack;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (head->prev != NULL)
		head = head->prev;

	printf("%d\n", head->n);

}
