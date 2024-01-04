#include "monty.h"

/**
 * op_pop - Pop a stack
 * @stack: Stack data
 * @line_number: Actual line of the monty file
*/
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop = *stack;

	if (stacklen == 0)
	{
		dprintf(1,
			"L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
		(*stack)->next->prev = NULL;
	if (stacklen != 1)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(pop);
	stacklen--;
}
