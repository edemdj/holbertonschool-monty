#include "monty.h"


stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;
	stack_t *node;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	node = *stack;
	new->n = n;
	new->prev = NULL;

	if (node != NULL)
	{
		while (node->prev != NULL)
			node = node->prev;
	}

	new->next = node;

	if (node != NULL)
		node->prev = new;

	*stack = new;
	return (new);
}