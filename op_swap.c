#include "monty.h"

/**
 * op_swap - Swap the top node of a stack by the next one
 * @stack: Stack data
 * @line_number: Actual line of the monty file
*/
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *last = *stack;

	if (!*stack || !stack || !head->next)
	{
		dprintf(2, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = head->next;
	head->prev = NULL;

	last->next = head->next;
	head->next = last;
	(head->next)->prev = head;

	*stack = head;
}
