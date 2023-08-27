#include "monty.h"

/**
 * push - Implements the push opcode
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty ByteCode file
 */
void push(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Could not allocate memory for new node.\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = *stack;
    *stack = new_node;
}

/**
 * pop - Implements the pop opcode
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty ByteCode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
    if (*stack)
    {
        stack_t *temp = *stack;
        *stack = (*stack)->next;
        
        if (*stack)
            (*stack)->prev = NULL;

        free(temp);
    }
    else
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
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

/**
 * swap - Implements the swap opcode
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty ByteCode file
 */
void swap(stack_t **stack, unsigned int line_number)
{
    if (*stack && (*stack)->next)
    {
        int temp = (*stack)->n;
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = temp;
    }
    else
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
}
