#include "monty.h"

/**
 * freeStack - Free the stack
 * @status: Status Code
 * @arg: The data to free
*/
void freeStack(int status, void *arg)
{
	stack_t **stack;
	stack_t *next;

	(void)status;
	if (status == 0)
		return;
	stack = (stack_t **)arg;
	if (*stack)
	{
		if ((*stack)->prev)
			(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}

/**
 * freeLine - Free the lineptr
 * @status: Status Code
 * @arg: The data to free
*/
void freeLine(int status, void *arg)
{
	char **lineptr = arg;

	if (status == 0)
		return;
	(void)status;
	if (*lineptr != NULL)
		free(*lineptr);
}

/**
 * closeFile - Close the opened file
 * @status: Status Code
 * @arg: The data to free
*/
void closeFile(int status, void *arg)
{
	FILE *fs;

	(void)status;
	if (status == 0)
		return;
	fs = (FILE *) arg;
	fclose(fs);
}
