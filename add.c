#include "monty.h"

/**
 * add - add the top two number of the stack
 * @stack: double pointer to the stack head
 * n: line number add is called
 *
 */
void add(stack_t **stack, unsigned int n)
{
	stack_t *head, *st2, *new;
	int sum;

	stack = stack;
	if (glob->head == NULL || glob->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack is too short\n", n);
		free_tokens();
		fclose(glob->fp);
		free_glob();
		exit(EXIT_FAILURE);
	}
	head = glob->head;
	st2 = head->next;
	sum = head->n + st2->n;
	pop(&(glob->head), n);
	glob->head = st2;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		malloc_fail();
	new->n = sum;
	new->next = st2->next;
	if (st2->next != NULL)
		st2->next->prev = new;
	pop(&(glob->head), n);
	glob->head = new;
}
