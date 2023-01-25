#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * parse_line - parses line and chooses function to be called
 * @line: the line to be parse containing the commands
 * @line_num: the instruction line
 * @head: pointer to pointer to head of stack
 * @mem_counter: counter for number of mallocs - number of free
 * Return: always 0 unless there is an error
 */
int parse_line(char *line, unsigned int line_num,
		stack_t **head, int mem_counter)
{
	char *token;
	unsigned int i = 0;
	char *x = 0;

	token = strtok(line, "\n\t\a\r :;");
	while (token && i < 1)
	{
		x = strchr(token, '#');
		i++;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\a\r ;:");
			if (token == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_num);
				exit(EXIT_FAILURE);
			}
			push(head, token, line_num, mem_counter);
		}
		else if (strcmp(token, "nop") == 0)
		{}
		else
		{
			if (get_func(token) != 0)
				get_func(token)(head, line_num);
			else if (x != NULL)
			{
				if (x - strtok(NULL, "\n\t\a\r ;:") + 1 == 1)
				{}
			}
			else
			{
				free_stack(*head, mem_counter);
				printf("L%d: unknown instruction %s\n", line_num, token);
				exit(EXIT_FAILURE);
			}
		}
	}
	return (0);
}
