#include "monty.h"

/**
 * parse_line - parses a line from bytecode file
 *
 * Return: pointer to a structure containing the opcode and the arg
 */
void parse_line(void)
{
	char *delim = " \n", *token = NULL, *linecpy = NULL;
	int i = 0;

	linecpy = malloc(sizeof(char) * (strlen(glob->line) + 1));
	if (linecpy == NULL)
		malloc_fail();
	strcpy(linecpy, glob->line);
	glob->n_tokens = 0;
	token = strtok(linecpy, delim);
	while (token)
	{
		glob->n_tokens += 1;
		token = strtok(NULL, delim);
	}
	strcpy(linecpy, glob->line);
	glob->tokens = malloc(sizeof(char *) * (glob->n_tokens + 1));
	if (glob->tokens == NULL)
		malloc_fail();
	token = strtok(linecpy, delim);
	while (token)
	{
		glob->tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (glob->tokens[i] == NULL)
			malloc_fail();
		strcpy(glob->tokens[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	glob->tokens[i] = NULL;
	free(linecpy);
}

/**
 * get_instruction - gets the opcode and it's corsponding function
 *
 * Return: pointer to the corsponding function
 */
void get_instruction(void)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", &push}, {"pall", &pall},
		{"pint", &pint}, {"pop", &pop},
		{"swap", &swap}, {"add", &add},
		{"nop", &nop}, {"sub", &sub},
		{"div", &divide}, {"mul", &mul},
		{"mod", &mod}, {NULL, NULL}
	};

	if (glob->n_tokens == 0)
		return;
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(glob->tokens[0], instructions[i].opcode) == 0)
		{
			glob->inst->opcode = instructions[i].opcode;
			glob->inst->f = instructions[i].f;
			return;
		}
		i++;
	}
	invalid_inst();
}
/**
 * execute_line - executes a line from the file
 *
 */
void execute_line(void)
{
	stack_t *node = NULL;

	get_instruction();
	if (glob->n_tokens == 0)
		return;
	glob->inst->f(&node, glob->line_num);
}
