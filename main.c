#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_t *stack = NULL; // Initialize your stack here

    // Read and process instructions from the file
    char line[1024];
    unsigned int line_number = 0;

    while (fgets(line, sizeof(line), file))
    {
        line_number++;
        // TODO: Parse line to extract opcode and arguments
        // TODO: Call the appropriate function based on the opcode
    }

    // TODO: Free memory and close file

    return EXIT_SUCCESS;
}
