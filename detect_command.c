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