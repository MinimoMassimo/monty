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
int parse_line(char *line, unsigned int line_num, stack_t **head, int mem_counter)
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
		else if (strcmp(token, "pall") == 0)
			pall(head, line_num);
		else if (strcmp(token, "pint") == 0)
			pint(head, line_num);
		else if (strcmp(token, "pop") == 0)
			pop(head, line_num);
		else if (strcmp(token, "swap") == 0)
			swap(head, line_num);
		else if (strcmp(token, "add") == 0)
			add(head, line_num);
		else if (strcmp(token, "nop") == 0)
		{}
		else if (strcmp(token, "div") == 0)
			div_stack(head, line_num);
		else if (strcmp(token, "sub") == 0)
			sub(head, line_num);
		else if (strcmp(token, "mul") == 0)
			mul(head, line_num);
		else if (strcmp(token, "mod") == 0)
			mod(head, line_num);
		else if (strcmp(token, "pchar") == 0)
			pchar(head, line_num);
		else if (strcmp(token, "pstr") == 0)
			pstr(head, line_num);
		else if (x != NULL)
		{
			if (x - strtok(NULL, "\n\t\a\r ;:") + 1 == 1)
			{}
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, token);
			exit(EXIT_FAILURE);
		}

	}
	return (0);
}
