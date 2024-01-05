#include "monty.h"

/**
 * numbersOnly - Check if a string is a number
 * @arg: String to check
 * Return: 1 if a number, 0 if not
*/
int numbersOnly(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}
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
	if (arg == NULL || numbersOnly(arg))
	{
		dprintf(1, "L%u: usage: push integer\n", line_number);
		free(new);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);

	new->n = n;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
