#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global variables
 * @head: the stack head
 * @line: string
 * @fp: file stream
 * @line_num: line number
 * @tokens: tokes from current line
 * @inst: instruction on the line
 * @n_tokens: number of token s from current line
 * @stack_size: number of node in the stack
 * @s_or_q: determines if we are using a stack or a queue
 *
 * Description: a global struct with nucessary variables
 */
typedef struct global_s
{
	stack_t *head;
	char *line;
	FILE *fp;
	int line_num;
	char **tokens;
	instruction_t *inst;
	int n_tokens;
	int stack_size;
	int s_or_q;
} g_vars;
extern g_vars *glob;

/** funcs **/
void parse_line(void);
void execute_line(void);
void free_tokens(void);
void free_glob(void);
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
/** fails **/
int malloc_fail(void);
int invalid_inst(void);
/** utils **/
int is_nan(char *);
#endif
