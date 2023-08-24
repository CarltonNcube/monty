#include "main.h"

/**
 * push - Pushes a value onto the stack.
 * @stack: Pointer to the top of the stack.
 * @value: Value to be pushed onto the stack.
 * @line_number: Line number in the file.
 *
 * This function pushes a new value onto the stack.
 *
 * @stack: Pointer to the top of the stack.
 * @value: Value to be pushed onto the stack.
 * @line_number: Line number in the file where the operation is performed.
 */

void push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		printf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;

	if (*stack);
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}
	*stack = new_node;
}

/**
 * palls - Print all values on the stack.
 *
 * @param stack Pointer to the top of the stack.
 * @param line_number Line number in the file.
 *
 * This function prints all the values currently stored on the stack.
 *
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file where the operation is performed.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
