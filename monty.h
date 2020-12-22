#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct moe_s - collection of variables
 * @mode: stack or queue
 * @fp: file to be read
 * @buf: the buffer
 *
 * Description: collection of variables
 * for stack, queues, LIFO, FIFO
 */

typedef struct mode_s
{
	int mode;
	FILE *fp;
	char *buf;
} moe_t;

extern moe_t moe;

int push(stack_t **st, unsigned int ln, char *pa);
void pall(stack_t **stack, unsigned int line_number);
void err_push(unsigned int ln);
void err_malloc(void);
#endif /* MONTY_H */
