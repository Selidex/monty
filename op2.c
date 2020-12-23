#include "monty.h"

/**
 *nop - does nothing
 *@stack: the stack
 *@line_number: the line number
 *Return: void, no return
 */

void nop(__attribute__((unused))stack_t **stack, unsigned int line_number)
{
	line_number = line_number * 2;
}
