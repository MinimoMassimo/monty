#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - adds a new node at the beggining of a dlistint_t list
 * @head: pointer to pointer to head of list
 * @val: value of the new node
 * @lines: line of instruction
 * Return: address of the new element or NULL if failed
 */
stack_t *push(stack_t **head, char *val, int lines)
{
	stack_t *new_node;
	int n;

	n = atoi(val);
	if (n == 0 || val == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", lines);
		exit(EXIT_FAILURE);
	}

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	if (*head == NULL)
	{
		*head = new_node;
		new_node->n = n;
		new_node->next = NULL;
		new_node->prev = NULL;
		return (new_node);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;
	return (new_node);
}
