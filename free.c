#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - frees stack
 * @head: pointer to the topmost element of stack
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	if (!head)
		return;
	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
}
