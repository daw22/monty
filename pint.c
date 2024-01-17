#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to stack head
 * @n: line number pint is called
 *
 */
void pint(stack_t **stack, unsigned int n)
{
	stack_t *head;

	stack = stack;
	n = n;
	head = glob->head;
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", n);
		fclose(glob->fp);
		free_tokens();
		free_glob();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
