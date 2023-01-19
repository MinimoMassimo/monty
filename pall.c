#include "monty.h"
#include <stdio.h>
#include <stddef.h>
/**
 * pall - prints all elements of stack
 * @h: pointer to the top stack
 * Return : the num of nodes
 */
int pall(stack_t *h)
{
	int nodes = 0;

	if (h == NULL)
		return (0);
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		nodes++;
	}
	return (nodes);
}
