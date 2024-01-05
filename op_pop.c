#include "monty.h"

/**
 * op_pop - Pop a stack
 * @stack: Stack data
 * @line_number: Actual line of the monty file
*/
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;

	if (!*stack || !stack)
	{
		dprintf(2, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
	{
		*stack = last->next;
		(*stack)->prev = NULL;
		free(last);
	} else
	{
		free(*stack);
		*stack = NULL;
	}
}
