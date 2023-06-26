#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * struct arg_s - Structure for argument and flag
 * @arg: Argument value
 * @flag: Flag value
 *
 * Description: Structure to hold an argument and flag values.
 */
typedef struct arg_s
{
    int arg;
    int flag;
} arg_t;

extern arg_t arg;

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value
 * @prev: Pointer to the previous element of the stack (or queue)
 * @next: Pointer to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure for stack, queues, LIFO, FIFO.
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its corresponding function
 * @opcode: The opcode
 * @f: Function pointer to handle the opcode
 *
 * Description: Structure to hold an opcode and its corresponding function.
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct line - Contents of a line and corresponding number
 * @contents: Array of tokens read from the line
 * @number: The line number
 *
 * Description: Structure to hold the contents of a line and its corresponding number.
 */
typedef struct line
{
    unsigned int number;
    char **content;
} line_t;

/**
 * struct meta_s - Metadata for the program
 * @buf: Buffer for reading lines
 * @stack: Pointer to the head node pointer of the stack
 * @file: Pointer to the file being read
 *
 * Description: Structure to hold metadata for the program.
 */
typedef struct meta_s
{
    char *buf;
    stack_t *stack;
    FILE *file;
} meta_t;

/* Important functions */
void (*get_op_func(line_t line, meta_t *meta))(stack_t **, unsigned int);
int _isalpha(int c);

/* Parse functions */
void parse_file(FILE *file);
void parse_line(line_t *line, char *buffer);

/* Verification functions */
bool comment_check(line_t line);
void push_check(line_t line, meta_t *meta, char *opcode);

/* Stack manipulation functions */
void push(stack_t **stack, unsigned int nline);
void pall(stack_t **stack, unsigned int nline);
void pint(stack_t **stack, unsigned int nline);
void pop(stack_t **stack, unsigned int nline);
void swap(stack_t **stack, unsigned int nline);
void nop(stack_t **stack, unsigned int nline);
void rotl(stack_t **stack, unsigned int nline);
void rotlop(stack_t **stack, unsigned int nline);
void rotrop(stack_t **stack, unsigned int nline);
void pchar(stack_t **stack, unsigned int nline);
void pstr(stack_t **stack, unsigned int nline);
void free_stack(stack_t **stack);
void nop(stack_t **stack, unsigned int nline);
void qpush(stack_t **stack, unsigned int nline);
void addqu(stack_t **stack, unsigned int nline);
void pushqu(stack_t **stack, unsigned int nline);
void stackqu(stack_t **stack, unsigned int nline);

#endif /* MONTY_H */
