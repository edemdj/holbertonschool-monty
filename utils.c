#include "monty.h"

void freeStack(int status, void *arg)
{
	stack_t **stack;
	stack_t *next;

    (void)status;
	stack = (stack_t **)arg;
	if (*stack)
	{
        if((*stack)->prev)
		    (*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	queue.stack_len = 0;
}

void freeLine(int status, void *arg)
{
	char **lineptr = arg;

	(void)status;
	if (*lineptr != NULL)
		free(*lineptr);
}

void closeFile(int status, void *arg)
{
	FILE *fs;

	(void)status;
	fs = (FILE *) arg;
	fclose(fs);
}