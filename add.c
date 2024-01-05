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
    stack_t *ptr;
    
    if (stacklen < 2)
    {
        dprintf(1, "L%u: can't add, stack too short/n", line_number);
        exit(EXIT_FAILURE);
    }
    
   (*stack)->next->n += (*stack)->n;
	ptr = *stack;
	(*stack) = (*stack)->next;
	(*stack)->next = NULL;
	free(ptr);
}
