#include "monty.h"

/**
 * pop - pops the stack
 * @stack: double pointer to stack head
 * @n: line number wher pop is called
 */
void pop(stack_t **stack, unsigned int n)
{
	stack_t *head;

	stack = stack;
	head = glob->head;
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", n);
		free_tokens();
		exit(EXIT_FAILURE);
	}
	glob->head = glob->head->next;
	free(head);
}
