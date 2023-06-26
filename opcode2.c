#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Pointer to the head node pointer of stack.
 * @nline: The line number.
 *
 * Return: Nothing.
 */
void rotl(stack_t **stack, unsigned int nline)
{
	stack_t *temp, *first;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	(void)nline;
	temp = *stack;
	first = temp->next;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	(*stack)->next = NULL;

	*stack = first;
	first->prev = NULL;
}

/**
 * rotlop - Rotates the stack to the left.
 * @stack: Pointer to the head node pointer of stack.
 * @nline: The line number.
 *
 * Return: Nothing.
 */
void rotlop(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	(void)nline;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = (*stack)->prev;
	(*stack)->prev = temp;
}

/**
 * rotrop - Rotates the stack to the right.
 * @stack: Pointer to the head node pointer of stack.
 * @nline: The line number.
 *
 * Return: Nothing.
 */
void rotrop(stack_t **stack, unsigned int nline)
{
	stack_t *temp, *last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	(void)nline;
	temp = *stack;
	last = *stack;

	while (last->next != NULL)
		last = last->next;

	*stack = last;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = temp;
	temp->prev = last;
}

/**
 * qpush - Pushes for a queue instead of a stack.
 * @stack: Pointer to the head node pointer of stack.
 * @nline: The line number.
 *
 * Return: Nothing.
 */
void qpush(stack_t **stack, unsigned int nline)
{
	stack_t *new, *temp;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new->n = arg.arg;
	new->prev = NULL;
	new->next = NULL;

	if (*stack == NULL)
	{
		*stack = new;
		return;
	}

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;
}
