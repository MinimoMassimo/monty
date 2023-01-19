#include "monty.h"
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

/**
 * isViable - checks if the input is one of 7 options
 * @str: the input
 * Return: a new value
 */
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

/**
 * get_func - calls the appropriate function depending on the input
 * @str: the input that identifies the appropriate function
 * @head: pointer to pointer to topmost element of stack
 * @val: string value of the value we want to push
 * @lines: instruction line
 * Return: nothing
 */
void get_func(char *str, stack_t **head, char *val, int lines)
{
	if (strcmp(str, "push") == 0)
		push(head, val, lines);
	if (strcmp(str, "pall") == 0)
		pall(*head);
	if (strcmp(str, "pint") == 0)
		pint(*head, lines);
	if (strcmp(str, "pop") == 0)
		pop(head, lines);
	if (strcmp(str, "swap") == 0)
		swap(head, lines);
	if (strcmp(str, "add") == 0)
		add(head, lines);
	if (strcmp(str, "nop") == 0)
	{}
}

/**
 * calling - the main thing really
 * @buff: what is read from the monty file
 * Return: 0 always
 */
int calling(char *buff)
{
	stack_t *head = NULL;
	char *token, *str;
	int line = 0;

	token = strtok(buff, "\n\t\a\r ;:");
	while (token != NULL)
	{
		str = isViable(token);
		if (strcmp(str, "") != 0)
		{
			token = strtok(NULL, "\n\t\a\r ;:");
			get_func(str, &head, token, line);
			line++;
			if (strcmp(str, "push") == 0)
				token = strtok(NULL, "\n\t\a\r ;:");
		}
		else if (strcmp(str, "") == 0)
		{
			printf("L%d: unknown instruction %s\n", line, token);
			exit(EXIT_FAILURE);
	}
	}
	return (0);
}


/**
 * main - the main function
 * @argc: the nuber of arguments it is taking
 * @argv: the argument values
 * Return: depends on the outcome
 */
int main(int argc, char **argv)
{
	int file, chars;
	char *buff;

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

	calling(buff);
	return (0);
}
