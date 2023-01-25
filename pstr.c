#include "monty.h"
#include <stdio.h>
#include <stddef.h>

/**
 * pstr - prints all elements of stack as string
 * @head: pointer to the top stack
 * @line: unused
 * Return: nothing
 */
void pstr(stack_t **head, __attribute__((unused)) unsigned int line)
{
	stack_t *h = *head;

	if (h == NULL)
	{
		printf("\n");
	}
	while (h)
	{
		if (h->n <= 0 || h->n > 127)
			break;
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
