#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * sub - subtracts top element from second top element of stack
 * @head: pointer to pointer to head of stack
 * @line: instruction line
 * Return: 0
 */
int sub(stack_t **head, int line)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n = temp->n - temp->prev->n;
	*head = temp;
	free(temp->prev);
	return (0);
}
