#include "monty.h"


stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;

	if(*stack == NULL)
	{
		*stack = new;
	} else
	{
		(*stack)->prev = new;
		new->next = *stack;
	}

	if (queue.queue == 0 || queue.stack_len == 0)
		*stack = new;
	return (new);
}