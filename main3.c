#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - this is the main file
 * @ac: the number of arguments passed
 * @av: the argumnets
 * Return: always 0
 */
int main(int ac, char **av)
{
	size_t bufsize = 100;
	char *buffer;
	char *s;
	FILE *file;
	unsigned int line_num = 0, mem_counter = 0;
	stack_t *head = NULL;

	if (ac <= 1 || ac > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	buffer = (char *)malloc(sizeof(bufsize * sizeof(char)));
	if (buffer == NULL)
	{
		free(buffer);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	s = fgets(buffer, bufsize, file);
	while (s != NULL)
	{
		line_num++;
		parse_line(buffer, line_num, &head, mem_counter);
		s = fgets(buffer, bufsize, file);
	}
	fclose(file);
	free_stack(head, mem_counter);
	free(buffer);
	/*printf("Memory counter (should be 0): %d\n", mem_counter);*/
	return (0);
}
