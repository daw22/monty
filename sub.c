#include "monty.h"

/**
 * sub - subs the number on the top of the stack from
 * the second top
 * @stack: double pointer to stack head
 * @n: line number sub is called
 *
 */
void sub(stack_t **stack, unsigned int n)
{
	stack_t *head;

	stack = stack;
	if (glob->head == NULL || glob->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", n);
		free_tokens();
		fclose(glob->fp);
		free_glob();
		exit(EXIT_FAILURE);
	}
	head = glob->head;
	head->next->n -= head->n;
	glob->head = head->next;
	glob->stack_size -= 1;
	free(head);
}
