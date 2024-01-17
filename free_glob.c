#include "monty.h"

/**
 * free_stack - free a stack
 * @head: head of the stack
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	if (head->next)
		free_stack(head->next);
	free(head);
}

/**
 * free_glob - free the global variables
 *
 */
void free_glob(void)
{
	if (glob == NULL)
		return;
	if (glob->line)
	{
		free(glob->line);
		glob->line = NULL;
	}
	if (glob->inst)
	{
		free(glob->inst);
		glob->inst = NULL;
	}
	if (glob->head)
	{
		free_stack(glob->head);
		glob->head = NULL;
	}
	free (glob);
}
