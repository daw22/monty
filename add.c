#include "monty.h"

/**
 * add - add the top two number of the stack
 * @stack: double pointer to the stack head
 * n: line number add is called
 *
 */
void add(stack_t **stack, unsigned int n)
{
	stack_t *head, *st2;
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
	st2->n = sum;
	pop(&(head), n);
}
