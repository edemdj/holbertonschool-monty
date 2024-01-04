#include "monty.h"

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

void op_push(stack_t **stack, unsigned int line_number)
{
    char *arg;
    int n;

    arg = strtok(NULL, "\n\t\r ");
    if (arg == NULL || numbersOnly(arg))
    {
        dprintf(1, "L%u: usage: push integer\n",
            line_number);
        exit(EXIT_FAILURE);
    }
    n = atoi(arg);
    if (!add_node(stack, n))
    {
        dprintf(1, "Error: unable to add node\n");
        exit(EXIT_FAILURE);
    }
    queue.stack_len++;
}