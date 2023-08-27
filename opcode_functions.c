#include "monty.h"

/**
 * push - Implements the push opcode
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty ByteCode file
 */
void push(stack_t **stack, int value unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - Implements the pall opcode
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty ByteCode file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - Implements the pint opcode
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty ByteCode file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

