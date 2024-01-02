#include "monty.h"

void detect_command(char *command, stack_t **stack, unsigned int lineCount)
{
    int found = 0;

    if(strcmp("push", command) == 0)
    {
        op_push(stack, lineCount);
        found = 1;
    }
    if(strcmp("pall", command) == 0)
    {
        /* Execute pall-related function */
        found = 1;
    }

    if(found == 0)
    {
        dprintf(1, "%u: Unknown command %s\n", 
            lineCount, command);
	    exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
	unsigned int lineCount = 0;
	FILE *file = NULL;
	char *lineptr = NULL;
    char *command = NULL;
    size_t buff = 0;

    if (argc != 2)
	{
		dprintf(1, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		dprintf(1, "Error: Unable to open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

    while (getline(&lineptr, &buff, file) != -1)
	{
		lineCount++;
		command = strtok(lineptr, "\n\t\r ");
		if (command != NULL && command[0] != '#')
		{
            detect_command(command, &stack, lineCount);
		}
	}
    exit(EXIT_SUCCESS);
}