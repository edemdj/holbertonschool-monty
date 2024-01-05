#include "monty.h"
/**
 * add - adds the top two elements of the stack
 *  @stack: the stack
 * @line_number: current line number of the bytecode file
 *
 * Return: Nothing
*/
void add(stack_t **stack, unsigned int line_number)
{
    stack_t *head;
    
    if (stacklen < 2)
    {
        dprintf(1, "L%u: can't add, stack too short/n", line_number);
        exit(EXIT_FAILURE);
    }
    
    int *ptr = NULL;
    ptr = ((head)->next)->n + head->n;
    free(head);
    head = ptr;
    head = *stack;

}
