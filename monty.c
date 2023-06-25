#include "monty.h"

/**
 * main - Entry point of the Monty interpreter
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		return EXIT_FAILURE;
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}

parse_file(file);

	fclose(file);

	return EXIT_SUCCESS;
}
