#include "monty.h"


int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
	unsigned int line_number = 0;
	FILE *file = NULL;
	char *lineptr = NULL;
    char *command = NULL;
    size_t buff = 0;

    if (argc != 2)
	{
		dprintf(1, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		dprintf(1, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

    while (getline(&lineptr, &buff, file) != -1)
	{
		line_number++;
		command = strtok(lineptr, "\n\t\r ");
		if (command != NULL && command[0] != '#')
		{
            detect_command(command, &stack, line_number);
		}
	}
    exit(EXIT_SUCCESS);
}
