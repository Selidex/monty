#include "monty.h"

/**
 *push - pushes an element to the top of stack/back of queue
 *@st: the stack/queue
 *@ln: the line number
 *@pa: the argument to push, if valid
 *Return: 1 on success, or function pointer on error
 */

int push(stack_t **st, unsigned int ln, char *pa)
{
	stack_t *new;
	int pai;

	if (pa == NULL)
	{	err_push(ln, st);
		return (1); }
	if (strcmp(pa, "0") == 0)
		pai = 0;
	else
	{
		if (atoi(pa) == 0)
		{	err_push(ln, st);
			return (1); }
		pai = atoi(pa);	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{	err_malloc(st);
		return (1); }
	new->n = pai;
	if (*st == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*st = new;
		return (1);
	}
	(*st)->next = new;
	new->prev = *st;
	new->next = NULL;
	*st = new;
	return (1);
}

/**
 *pall - prints the stack/queue
 *@stack: the stack/queue
 *@line_number: the line number
 *Return: void no return
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	line_number = line_number * 1;
	if (*stack == NULL)
		return;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
