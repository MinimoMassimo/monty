#include "monty.h"
#include <stdio.h>
#include <stddef.h>
/**
 * pstr - prints all elements of stack as string
 * @h: pointer to the top stack
 * Return : the num of nodes
 */
int pstr(stack_t *h)
{
	int nodes = 0;

	if (h == NULL)
	{
		printf("\n");
		return (nodes);
	}
	while (h)
	{
		if (h->n <= 0 || h->n > 127)
			break;
		printf("%c", h->n);
		h = h->next;
		nodes++;
	}
	printf("\n");
	return (nodes);
}
