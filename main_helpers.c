#include "monty.h"
#include <string.h>
#include <stdio.h>

/**
 * parse_instruction - Parses a single instruction from a line of input
 * @line: Input line containing the instruction
 * @opcode: Pointer to store the opcode
 * @arg: Pointer to store the argument (if any)
 */

void parse_instruction(char *line, char **opcode, char **arg)
{
    char *token;

    *opcode = NULL;
    *arg = NULL;

    token = strtok(line, " \t\n");

    if (token == NULL)
        return;

    *opcode = strdup(token);

    token = strtok(NULL, " \t\n");
    if (token != NULL)
        *arg = strdup(token);
}

/**
 * execute_instruction - Executes a single Monty ByteCode instruction
 * @opcode: The opcode to execute
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty ByteCode file
 */
void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{
    size_t i;
    
    // Move variable declaration outside the loop
    for (i = 0; i < NUM_OPCODES; i++)
    {
        if (strcmp(opcode, opcode_functions[i].opcode) == 0)
        {
            opcode_functions[i].func(stack, line_number);
            return;
        }
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}


/**
 * main_loop - Main loop for reading and executing instructions from input file
 * @file: Pointer to the input file
 * @stack: Pointer to the stack
 */
void main_loop(FILE *file)
{
    char *line = NULL;
    size_t len = 0;

	while (getline(&line, &len, file) != -1)
	{
	line_number++;

	parse_instruction(line, &opcode, &arg);

	if (opcode != NULL)
	{
		execute_instruction(opcode, stack, line_number);
	}

	free(opcode);
	free(arg);
	}

	free(line);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Could not open file '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }

    main_loop(file);

    fclose(file);
    return EXIT_SUCCESS;
}
