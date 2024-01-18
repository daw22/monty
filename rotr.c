#include "monty.h"

/**
 * rotr - make last element of the stack the first
 * @stack: double pointer to the stack head
 * @n: line number rotr is called
 *
 */
void rotr(stack_t **stack, unsigned int n)
{
	stack_t *head;

	stack = stack;
	n = n;
	head = glob->head;
	if (glob->stack_size > 1)
	{
		while (head->next != NULL)
			head = head->next;
		head->prev->next = NULL;
		head->prev = NULL;
		head->next = glob->head;
		glob->head->prev = head;
		glob->head = head;
	}
}
