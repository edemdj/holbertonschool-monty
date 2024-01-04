#include "monty.h"

/**
 * pall - removes the top element of the stack
 * @stack: the stack
 * @line_number: current line number of the bytecode file
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;
	(void)(line_number);
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
