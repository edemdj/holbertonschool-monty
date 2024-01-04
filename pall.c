#include "monty.h"

/**
 * pall - removes the top element of the stack
 * @stack: the stack
 * @line_number: current line number of the bytecode file
 *@n: integer
 * Return: Nothing
 */
void pall(stack_t **stack)
{
    stack_t *head;
    head = *stack;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		
	}
}
