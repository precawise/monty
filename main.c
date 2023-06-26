#include "monty.h"

/**
 * main - Entry point of the Monty interpreter
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
    FILE *file;

    file = fopen("your_script_file.m", "r");
    if (!file)
    {
        fprintf(stderr, "Error: Failed to open script file\n");
        return 1;
    }

    parse_file(file);

    fclose(file);

    return 0;
}

