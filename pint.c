#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * pint - prints top element of stack
 * @h: pointer to the top stack
 * @line: the line of instruction
 * Return: nothing
 */
void pint(stack_t **head, unsigned int line)
{
	stack_t *h = *head;
	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", h->n);
}
