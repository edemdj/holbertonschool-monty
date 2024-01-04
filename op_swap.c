#include "monty.h"

/**
 * op_swap - Swap the top node of a stack by the next one
 * @stack: Stack data
 * @line_number: Actual line of the monty file
*/
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (stacklen < 2)
	{
		dprintf(1,
			"L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (stacklen == 2)
	{
		*stack = (*stack)->next;
		return;
	}
	next = (*stack)->next;
	next->prev = (*stack)->prev;
	if ((*stack)->prev)
		(*stack)->prev->next = next;
	(*stack)->prev = next;
	(*stack)->next = next->next;
	if (next->next)
		next->next->prev = *stack;
	next->next = *stack;
	*stack = next;
}
