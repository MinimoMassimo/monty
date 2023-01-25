#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * pchar - prints top element of stack
 * @h: pointer to the top stack
 * @line: the line of instruction
 * Return: 0 or 1
 */
void pchar(stack_t **head, unsigned int line)
{
	stack_t *h = *head;
	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	if (h->n < 0 || h->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
