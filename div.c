#include "monty.h"

/**
 * divide - divides the second top in the stack with
 * the top on the stack
 * @stack: double pointer to stack head
 * @n: line number div is called
 *
 */
void divide(stack_t **stack, unsigned int n)
{
	stack_t *head;

	stack = stack;
	if (glob->head == NULL || glob->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", n);
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
	head->next->n /= head->n;
	glob->head = head->next;
	glob->stack_size -= 1;
	free(head);
}
