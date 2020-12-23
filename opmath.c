#include "monty.h"

/**
 *add - adds tos + tos1
 *@stack: the stack
 *@line_number: line number
 *Return: void no return
 */

void add(stack_t **stack, unsigned int line_number)
{
	int len = 0, temp = 0;
	stack_t *current = *stack;

	if (*stack != NULL)
	{
		while (current->prev != NULL)
		{
			current = current->prev;
			len++;
		}
		len++;
	}
	if (*stack == NULL || len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	*stack = (*stack)->prev;
	temp = (*stack)->n + current->n;
	(*stack)->n = temp;
	(*stack)->next = NULL;
	free(current);
}

/**
 *sub - sub tos - tos1
 *@stack: the stack
 *@line_number: line number
 *Return: void no return
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int len = 0, temp = 0;
	stack_t *current = *stack;

	if (*stack != NULL)
	{
		while (current->prev != NULL)
		{
			current = current->prev;
			len++;
		}
		len++;
		}
	if (*stack == NULL || len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	*stack = (*stack)->prev;
	temp = (*stack)->n - current->n;
	(*stack)->n = temp;
	(*stack)->next = NULL;
	free(current);
}
