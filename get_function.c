#include "monty.h"
#include <string.h>

/**
 * get_func - selects correct function
 * @token: the instruction
 * Return: pointer to correct function
 */
void (*get_func(char *token))(stack_t **head, unsigned int line_num)
{
	int i = 0;

	instruction_t instructions[] = {
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"mod", mod},
		{"div", div_stack},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	while (instructions[i].f != NULL)
	{
		if (strcmp(token, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	return (NULL);
}
