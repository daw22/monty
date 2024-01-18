#include "monty.h"

/**
 * swap - swap the top two elements of the stack
 * @stack: double pointer to stack head
 * @n: the line number swap is called
 *
 */
void swap(stack_t **stack, unsigned int n)
{
	stack_t *head, *sw2;

	stack = stack;
	head = glob->head;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", n);
		free_tokens();
		fclose(glob->fp);
		free_glob();
		exit(EXIT_FAILURE);
	}
	sw2 = head->next;
	head->next = sw2->next;
	if (head->next != NULL)
		sw2->next->prev = head;
	head->prev = sw2;
	sw2->next = head;
	sw2->prev = NULL;
	glob->head = sw2;
}
