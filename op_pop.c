#include "monty.h"

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop = *stack;

	if (queue.stack_len == 0)
	{
		dprintf(1,
			"L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
    if((*stack)->next)
	    (*stack)->next->prev = NULL;
	if (queue.stack_len != 1)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(pop);
	queue.stack_len--;
}