#include "monty.h"

/**
 * pall - prints the value of all the node in the stack
 * @stack: double pointer to the stack's head
 * @n: line number this pall is called
 *
 */
void pall(stack_t **stack, unsigned int n)
{
	stack_t *head;

	if (glob->head == NULL)
		return;
	head = glob->head;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
