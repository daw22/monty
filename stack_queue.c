#include "monty.h"

/**
 * stack - changes to stack mode
 * @stack: double pointer to stack head
 * @n: line number stack is called
 *
 */
void stack(stack_t **stack, unsigned int n)
{
	stack = stack;
	n = n;
	glob->s_or_q = 1;
}

/**
 * queue - changes to queue mode
 * @stack: double pointer to stack head
 * @n: line number stack is called
 *
 */
void queue(stack_t **stack, unsigned int n)
{
	stack = stack;
	n = n;
	glob->s_or_q = 2;
}
