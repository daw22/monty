#include "monty.h"

/**
 * pstr - prints all nodes of the stack as ascii
 * character
 * @stack: double pointer to stack head
 * @n: line number pstr is called
 *
 */
void pstr(stack_t **stack, unsigned int n)
{
	stack_t *head;

	stack = stack;
	n = n;
	head = glob->head;
	while (head != NULL)
	{
		if (head->n == 0)
			break;
		if (head->n < 0 || head->n > 127)
			break;
		printf("%c", head->n);
		head = head->next;
	}
	printf("\n");
}
