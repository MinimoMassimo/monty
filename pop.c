#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop - removes topmost element of the stack
 * @head: pointer to pointer of topmost element
 * @line: the line of instruction
 * Return: 1 or 0
 */
int pop(stack_t **head, int line)
{
	stack_t *temp;

	if (*head == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
	if (*head != NULL)
		(*head)->prev = NULL;
	return (1);
}
