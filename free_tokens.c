#include "monty.h"

/**
 * free_tokens - free tokens
 */
void free_tokens(void)
{
	int i;

	for (i = 0; i < glob->n_tokens; i++)
	{
		free(glob->tokens[i]);
	}
	free(glob->tokens);
}
