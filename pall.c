#include "monty.h"
#include <stdio.h>
#include <stddef.h>
/**
 * pall - prints all elements of stack
 * @h: pointer to the top stack
 * Return: nothing
 */
void pall(stack_t **head, __attribute__((unused)) unsigned int line)
{
	stack_t *h = *head;

	if (h == NULL)
		return ;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
