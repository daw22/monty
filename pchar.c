#include "monty.h"

/**
 * pchar - prints the ascii character for the value stored
 * on the top of the stack
 * @stack: double pointer to head of stack
 * @n: line number pchar is called
 *
 */
void pchar(stack_t **stack, unsigned int n)
{
	stack_t *head;

	stack = stack;
	if (glob->head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", n);
		free_tokens();
		fclose(glob->fp);
		free_glob();
		exit(EXIT_FAILURE);
	}
	head = glob->head;
	if (head->n < 0 || head->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", n);
		free_tokens();
		fclose(glob->fp);
		free_glob();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", head->n);
}
