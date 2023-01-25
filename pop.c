#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop - removes topmost element of the stack
 * @head: pointer to pointer of topmost element
 * @line: the line of instruction
 * Return: nothing
 */
void pop(stack_t **head, unsigned int line)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
	if (*head != NULL)
		(*head)->prev = NULL;
}
