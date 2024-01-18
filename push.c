#include "monty.h"

/**
 * push - pushes a number to the stack
 * @stack: double pointer to the head of the stack
 * @n: the line number push is called in the file
 *
 */
void push(stack_t **stack, unsigned int n)
{
	if (is_nan(glob->tokens[1]) || glob->n_tokens <= 1)
	{
		fclose(glob->fp);
		free_tokens();
		free_glob();
		fprintf(stderr, "L%d: usage: push integer\n", n);
		exit(EXIT_FAILURE);
	}
	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_fail();
	(*stack)->n = (int) atoi(glob->tokens[1]);
	(*stack)->next = (*stack)->prev = NULL;
	if (glob->head == NULL)
		glob->head = *stack;
	else
	{
		(*stack)->next = glob->head;
		glob->head->prev = *stack;
		glob->head = *stack;
	}
	glob->stack_size += 1;
}
