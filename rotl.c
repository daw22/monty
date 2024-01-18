#include "monty.h"

/**
 * rot1 - changes the place of the top and bottom of the stack
 * @stack: double pointer to the stack head
 * @n: line number rotl is called
 *
 */
void rotl(stack_t **stack, unsigned int n)
{
	stack_t *head, *tmp;

	stack = stack;
	n = n;
	head = glob->head;
	if (glob->stack_size > 1)
	{
		while (head->next != NULL)
			head = head->next;
		tmp = glob->head->next;
		head->next = glob->head;
		glob->head->next = NULL;
		glob->head->prev = head;
		glob->head = tmp;

	}
}
