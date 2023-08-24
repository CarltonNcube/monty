#include "main.h"

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

#include "main.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    // ... (file opening and line reading logic)

    stack_t *stack = NULL;

    // ... (loop through lines, parse opcodes, and execute instructions)

    fclose(file);

    return 0;
}
