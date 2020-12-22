#include "monty.h"

/**
 *err_push - prints error message
 *@st: the stack
 *@ln: line number
 *Return: void no return
 */

void err_push(unsigned int ln, stack_t **st)
{
	fprintf(stderr, "L%d: usage: push integer\n", ln);
	free_stack(st);
	free(moe.buf);
	fclose(moe.fp);
	exit(EXIT_FAILURE);
}

/**
 *err_malloc - prints error message
 *@st: the stack
 *Return: nothing
 */

void err_malloc(stack_t **st)
{
	fprintf(stderr, "Error: malloc failed\n");
	free(moe.buf);
	free_stack(st);
	fclose(moe.fp);
	exit(EXIT_FAILURE);
}
