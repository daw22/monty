#include "monty.h"

/**
 * mul - multiplies the top two number of the stack
 * @stack: double pointer to the stack head
 * @n: line number add is called
 *
 */
void mul(stack_t **stack, unsigned int n)
{
	stack_t *head;

	stack = stack;
	if (glob->head == NULL || glob->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", n);
		free_tokens();
		fclose(glob->fp);
		free_glob();
		exit(EXIT_FAILURE);
	}
	head = glob->head;
	head->next->n = head->n * head->next->n;
	glob->head = head->next;
	glob->stack_size -= 1;
	free(head);
}
