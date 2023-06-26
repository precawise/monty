#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the head node pointer of the stack
 * @nline: the line number
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int nline)
{
	stack_t *top;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", nline);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	while (top->prev != NULL)
		top = top->prev;

	printf("%d\n", top->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the head node pointer of the stack
 * @nline: the line number
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int nline)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", nline);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the head node pointer of the stack
 * @nline: the line number
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int nline)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * pchar - prints the character at the top of the stack
 * @stack: pointer to the head node pointer of the stack
 * @nline: the line number
 * Return: Nothing
 */
void pchar(stack_t **stack, unsigned int nline)
{
	char c;
	stack_t *top;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", nline);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	while (top->prev != NULL)
		top = top->prev;

	c = top->n;
	if (_isalpha(top->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", nline);
		exit(EXIT_FAILURE);
	}

	putchar(c);
	putchar('\n');
}

/**
 * pstr - prints a string of characters from the stack
 * @stack: pointer to the head node pointer of the stack
 * @nline: the line number
 * Return: Nothing
 */
void pstr(stack_t **stack, unsigned int nline)
{
	int idx = 0;
	char result[1024] = "";
	char c;
	stack_t *temp;

	temp = *stack;
	(void)nline;

	while (temp)
	{
		if (temp->n == 0)
			break;
		if (_isalpha(temp->n) == 0)
			break;

		c = temp->n;
		putchar(c);
		result[idx] += c;
		temp = temp->next;
		idx++;
	}

	putchar('\n');
}
