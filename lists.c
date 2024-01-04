#include "monty.h"

/**
 * add_node - Add a node to a stack
 * @stack: Stack data
 * @n: Value of the node
 * Return: the adress of the new node
*/
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;

	if (*stack == NULL)
	{
		*stack = new;
	} else
	{
		(*stack)->prev = new;
		new->next = *stack;
	}

	if (stacklen == 0)
		*stack = new;
	return (new);
}
