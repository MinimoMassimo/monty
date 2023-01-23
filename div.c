#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * div_stack - divides second top element by first element of stack
 * @head: pointer to pointer to head of stack
 * @line: instruction line
 * Return: 0
 */
int div_stack(stack_t **head, int line)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n = temp->n / temp->prev->n;
	*head = temp;
	free(temp->prev);
	return (0);
}
