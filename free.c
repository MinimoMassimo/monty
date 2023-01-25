#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - frees stack
 * @head: pointer to the topmost element of stack
 * @mem_counter: keeps track of num of malloc and free called
 * Return: nothing
 */
void free_stack(stack_t *head, int mem_counter)
{
	if (!head)
		return;
	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
		mem_counter--;
	}
	free(head);
	mem_counter--;
}
