#include "main.h"

/**
 * pop - Removes the top element from the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 *
 * This function removes the top element from the stack.
 *
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file where the operation is performed.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (*stack)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
