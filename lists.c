#include "monty.h"


stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;
	stack_t *node;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	node = *stack;
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (node != NULL)
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
	else
		*stack = new;

	new->prev = node;
	return (new);
}