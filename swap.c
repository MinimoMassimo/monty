#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - swaps the first two elements of the stack
 * @head: pointer to pointer of topmost element
 * @line: instruction line
 * Return: always 1
 */
int swap(stack_t **head, int line)
{
	stack_t *B, *A;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short", line);
		exit(EXIT_FAILURE);
	}
	A = *head;
	B = (*head)->next;
	if (B->next != NULL)
		B->next->prev = *head;
	A->next = B->next;
	A->prev = B;
	B->next = A;
	B->prev = NULL;
	*head = B;
	return (1);
}
