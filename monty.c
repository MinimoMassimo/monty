#include "monty.h"
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

char *isViable(char *str)
{
	char *res = "";

	if (strcmp(str, "push") == 0)
		res = "push";
	else if (strcmp(str, "pall") == 0)
		res = "pall";
	else if (strcmp(str, "pint") == 0)
		res = "pint";
	else if (strcmp(str, "pop") == 0)
		res = "pop";
	else if (strcmp(str, "swap") == 0)
		res = "swap";
	else if (strcmp(str, "add") == 0)
		res = "add";
	else if (strcmp(str, "nop") == 0)
		res = "nop";

	return (res);
}

void get_func(char *str, stack_t **head, char *val, int lines)
{
	if (strcmp(str, "push") == 0)
		push(head, val, lines);
	if (strcmp(str,"pall") == 0)
	{
		printf("printing");
		pall(*head);
	}
}

int main(int argc, char **argv)
{
	int file, chars, lines;
	char *buff, *token, *str;
	stack_t *head = NULL;

	if (argc <= 1 || argc > 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = open(argv[1], O_RDONLY);
	if (file < 0)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	buff = malloc(sizeof(char) * 10000);
	if (buff == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	chars = read(file, buff, 10000);
	if (chars < 0)
	{
		free(buff);
		close(file);
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	token = strtok(buff, "\n\t\a\r ;:");
	lines = 0;
	while (token != NULL)
	{
		str = isViable(token);
		if (strcmp(str, "") != 0)
		{
			token = strtok(NULL, "\n\t\a\r ;:");
			get_func(str, &head, token, lines);
			lines++;
		}
		if (strcmp(str, "") == 0)
		{
			printf("L%d: unknown instruction %s\n", lines, token);
			exit(EXIT_FAILURE);
		}
		
				
		/*token = strtok(buff, "\n");*/

		printf("line: %d token: %s\n", lines, token);
		token = strtok(NULL, "\n\t\a\r ;:");
		/*lines++;*/
	}
	return (0);
}
