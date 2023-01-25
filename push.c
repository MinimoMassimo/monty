#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * push - adds a new node at the beggining of a dlistint_t list
 * @head: pointer to pointer to head of list
 * @val: value of the new node
 * @lines: line of instruction
 * @mem_counter: keeps track of number of mallocs and frees
 * Return: address of the new element or NULL if failed
 */
stack_t *push(stack_t **head, char *val, int unsigned lines, int mem_counter)
{
	stack_t *new_node;
	int n;
	size_t i = 0;

	n = atoi(val);

	for (; i < strlen(val); i++)
	{
		if (val[0] == '-')
			continue;
		if (val[i] > '9' || val[i] < '0')
		{
			fprintf(stderr, "L%d: usage: push integer\n", lines);
			exit(EXIT_FAILURE);
		}
	}

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	mem_counter++;
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
