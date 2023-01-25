#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * mul - multiplies top two elements of stack
 * @head: pointer to pointer to head of stack
 * @line: instruction line
 * Return: nothing
 */
void mul(stack_t **head, unsigned int line)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n = temp->prev->n * temp->n;
	*head = temp;
	free(temp->prev);
}
