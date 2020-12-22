#include "monty.h"

/**
 *err_push - prints error message
 *@ln: line number
 *Return: void no return
 */

void err_push(unsigned int ln)
{
	fprintf(stderr, "L%d: usage: push integer\n", ln);
	free(moe.buf);
	fclose(moe.fp);
	exit(EXIT_FAILURE);
}

/**
 *err_malloc - prints error message
 *Return: nothing
 */

void err_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free(moe.buf);
	fclose(moe.fp);
	exit(EXIT_FAILURE);
}
