#include "monty.h"

/**
 * mod - calculates the reminder from the division of
 * the second on the stack and the top
 * @stack: double pointer to the stack head
 * @n: line number add is called
 *
 */
void mod(stack_t **stack, unsigned int n)
{
	stack_t *head;

	stack = stack;
	if (glob->head == NULL || glob->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", n);
		free_tokens();
		fclose(glob->fp);
		free_glob();
		exit(EXIT_FAILURE);
	}
	if (glob->head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", n);
		free_tokens();
		fclose(glob->fp);
		free_glob();
		exit(EXIT_FAILURE);
	}
	head = glob->head;
	head->next->n = head->next->n % head->n;
	glob->head = head->next;
	glob->stack_size -= 1;
	free(head);
}
