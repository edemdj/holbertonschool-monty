#include "monty.h"

void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (queue.stack_len < 2)
	{
		dprintf(1,
			"L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (queue.stack_len == 2)
	{
		*stack = (*stack)->next;
		return;
	}
	next = (*stack)->next;
	next->prev = (*stack)->prev;
    if((*stack)->prev)
	    (*stack)->prev->next = next;
	(*stack)->prev = next;
	(*stack)->next = next->next;
    if(next->next)
	    next->next->prev = *stack;
	next->next = *stack;
	*stack = next;
}