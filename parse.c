#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_line(char *line, int line_num, stack_t **head)
{
	char *token;
	unsigned int i = 0;

	token = strtok(line, "\n\t\a\r :;");
	while (token && i < 1)
	{
		i++;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\a\r ;:");
			push(head, token, line_num);
		}
		else if (strcmp(token, "pall") == 0)
			pall(*head);
		else if (strcmp(token, "pint") == 0)
			pint(*head, line_num);
		else if (strcmp(token, "pop") == 0)
			pop(head, line_num);
		else if (strcmp(token, "swap") == 0)
			swap(head, line_num);
		else if (strcmp(token, "add") == 0)
			add(head, line_num);
		else if (strcmp(token, "nop") == 0)
		{}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, token);
			exit(EXIT_FAILURE);
		}

	}
	return (0);
}
