#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - swaps the first two elements of the stack
 * @head: pointer to pointer of topmost element
 * @line: instruction line
 * Return: nothing
 */
void swap(stack_t **head, unsigned int line)
{
	stack_t *B, *A;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
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
}
