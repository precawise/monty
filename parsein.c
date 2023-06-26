#include "monty.h"
#include <stdio.h>

/**
 * parseline - tokenizes a line of text, storing it in line struct
 * @line: struct containing line contents and line number
 * @buffer: string of text read from script file
 *
 * Return: Nothing
 */
void parseline(line_t *line, char *buffer)
{
    unsigned int i;
    char *token = NULL;

    line->content = malloc(sizeof(char *) * 3);
    if (!line->content)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(buffer, " '\n'");
    for (i = 0; token && i < 2; i++)
    {
        line->content[i] = token;
        token = strtok(NULL, " \n");
    }

    line->content[i] = NULL;
}

/**
 * parsefile - reads and parses file one line at a time
 * @file: the script to be read
 *
 * Return: Nothing
 */
void parsefile(FILE *file)
{
    meta_t *meta = NULL;
    line_t line;
    char buffer[1024];
    size_t size = sizeof(buffer);

    meta = malloc(sizeof(meta_t));
    if (!meta)
    {
        fprintf(stderr, "Error: malloc failed");
        exit(EXIT_FAILURE);
    }

    line.number = 0;
    line.content = NULL;

    meta->file = file;
    meta->stack = NULL;
    meta->buf = NULL;

    while (fgets(buffer, size, meta->file) != NULL)
    {
        line.number++;
        buffer[strcspn(buffer, "\n")] = '\0';

        parseline(&line, buffer);
        if (line.content)
            get_op_func(line, meta)(&(meta->stack), line.number);
    }

    free(meta->buf);
    free_stack(&(meta->stack));
    fclose(meta->file);
    free(meta);
}
