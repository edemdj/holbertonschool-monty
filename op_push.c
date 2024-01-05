#include "monty.h"

/**
 * op_push - Push a node in a stack
 * @stack: Stack data
 * @line_number: Actual line of the monty file
*/
void op_push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	stack_t *new = NULL;
	int n;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free(new);
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	arg = strtok(NULL, "\n\t\r ");
	n = atoi(arg);
	if (n == 0)
	{
		dprintf(2, "L%i: usage: push integer\n", line_number);
		free(new);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
