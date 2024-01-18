#include "monty.h"

g_vars *glob = NULL;
void init_glob(void);
/**
 * main - entry point of the program
 * @argc: number of args
 * @argv: vector of args
 *
 * Return: Always 0 on success
 */
int main(int argc, char **argv)
{
	size_t len = 0;

	/** validate args **/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	/** init glob **/
	init_glob();
	/** try open file **/
	glob->fp = fopen(argv[1], "r");
	if (glob->fp == NULL)
	{
		/**fprintf(stderr, "Error: Can't open file %s\n", argv[1]);**/
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	/** read ,parse and execute file **/
	while (getline(&(glob->line), &len, glob->fp) != -1)
	{
		parse_line();

		if (glob->tokens[0] == NULL)
		{
			glob->line_num += 1;
			free_tokens();
			continue;
		}
		glob->line_num += 1;
		execute_line();
		free_tokens();
	}
	fclose(glob->fp);
	free_glob();
	return (0);
}

/**
 * init_glob - intializes global variables
 */
void init_glob(void)
{
	glob = malloc(sizeof(g_vars));
	if (glob == NULL)
		malloc_fail();
	glob->inst = malloc(sizeof(instruction_t));
	if (glob->inst == NULL)
		malloc_fail();
	glob->line_num = 0;
	glob->head = NULL;
	glob->s_or_q = 1;
	glob->stack_size = 0;
	glob->line = NULL;
	glob->fp = NULL;
}
