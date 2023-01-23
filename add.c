#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add - sums top two elements of stack
 * @head: pointer to pointer to head of stack
 * @line: instruction line
 * Return: 0
 */
int add(stack_t **head, int line)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf("L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n = temp->prev->n + temp->n;
	*head = temp;
	free(temp->prev);
	return (0);
}
