#include "monty.h"

/**
 * malloc_fail - handdles malloc fail
 *
 * Return: exit status
 */
int malloc_fail(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * invalid_inst - handles invalid instruction
 *
 * Return: exit status
 */
int invalid_inst(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			glob->line_num, glob->tokens[0]);
	free_tokens();
	fclose(glob->fp);
	free_glob();
	exit(EXIT_FAILURE);
}
