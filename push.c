#include "monty.h"

/**
 * push - Pushes an element onto a stack or queue.
 * @stack: Pointer to pointer to top or front node.
 * @line_number: Line number in file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n")
			exit(EXIT_FAILURE);
	}
	value = atoi(strtok(NULL, "\n\t\r "));
	new_node->n = value;
	new_node->prev = NULL;
	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	else
	}
	new_node->next = NULL;
	}
	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack or queue.
 * @stack: Pointer to pointer to top or front node.
 * @line_number: Line number in file.
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

