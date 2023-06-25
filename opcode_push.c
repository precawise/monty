#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the stack
 * @nline: line number in the file
 */
void push(stack_t **stack, unsigned int nline)
{
	int value;

	if (arg.flag == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", nline);
		exit(EXIT_FAILURE);
	}

	value = arg.arg;

	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
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
 * pall - prints all the values on the stack
 * @stack: double pointer to the stack
 * @nline: line number in the file
 */
void pall(stack_t **stack, unsigned int nline)
{
	stack_t *current = *stack;

	(void)nline;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
