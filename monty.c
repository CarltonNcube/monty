#include <stdio.h>
#include <stdlib.h>

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

    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, file) != -1)
    {
	printf("Line: %s", line);
    }

    free(line);
    fclose(file);

    return EXIT_SUCCESS;
}

