#include "monty.h"

arg_t arg = {0, 0};

/**
 * comment_check - Checks if the line is a comment.
 * @line: Struct containing line contents and line number.
 *
 * Return: true if comment, else false.
 */
bool comment_check(line_t line)
{
	if (!line.content[0] || line.content[0][0] == '#')
	{
		free(line.content);
		return true;
	}

	return false;
}

/**
 * argument_check - Verifies if the argument is a valid integer.
 * @token: The argument to be checked.
 *
 * Return: true if valid argument, else false.
 */
bool argument_check(char *token)
{
	if (!token)
		return false;

	if (token[0] == '-')
		token++;

	for (; *token != '\0'; token++)
	{
		if (*token < '0' || *token > '9')
			return false;
	}

	return true;
}

/**
 * push_check - Checks if the opcode is "push" and sets the global argument variable if true.
 * @line: Struct containing line contents and line number.
 * @opcode: The opcode to compare.
 * @meta: Struct containing all allocated memory.
 *
 * Return: Nothing.
 */
void push_check(line_t line, meta_t *meta, char *opcode)
{
	if (strcmp(opcode, "push") == 0)
	{
		if (!argument_check(line.content[1]))
		{
			free(line.content);
			fprintf(stderr, "L%d: usage: push integer\n", line.number);
			free(meta->buf);
			free_stack(&(meta->stack));
			fclose(meta->file);
			free(meta);
			exit(EXIT_FAILURE);
		}

		arg.arg = atoi(line.content[1]);
	}

	free(line.content);
}
