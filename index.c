#include "monty.h"

moe_t moe;

/**
 *dn - does nothing
 *Return: void no return
 */

void free_stack(stack_t **st)
{
	stack_t *current;

	current = *st;

	while (*st != NULL && (*st)->next != NULL)
	{
		current = (*st)->next;
		free(*st);
		(*st) = current;
	}
	free(*st);
}

void dn(void)
{
	int i = 0;

	i = i * 2;
}

/**
 *c_fn - checks if the opcode is valid, and if so runs it
 *@buf: the opcode
 *Return: either a function pointer, or neg 1 on failure
 */

void (*c_fn(char *buf))(stack_t **, unsigned int)
{
	instruction_t inst[] =	{
		{"pall", pall},
		{NULL, NULL}
	};
	int i, oc = 1;
	void (*f)();

	f = &dn;
	if (buf == NULL || strcmp(buf, "\n") == 0)
		return (NULL);
	for (i = 0; i < oc; i++)
	{
		if (strcmp(buf, inst[i].opcode) == 0)
		{
			return (inst[i].f);
		}
	}
	moe.mode = 3;
	return (f);
}

/**
 *rmsp - removes excess space from a string
 *@str: the string being trimmed
 *Return: void no return
 */

void rmsp(char *str)
{
	int i = 0, j = 0;

	strtok(str, "\n");
	for (; str[i] != '\0'; i++)
	{
		while (str[i] == ' ' && (str[i + 1] == ' '
					  || str[i + 1] == '\0'
					 || str[i + 1] == '\n'))
			i++;
		if (j == 0 && str[i] == ' ')
			i++;
		str[j] = str[i];
		j++;
	}
	str[j] = '\0';
	strtok(str, " ");
}

/**
 *main - entry point for monty intepretor
 *@argc: number of arguments passed
 *@argv: array of arguments
 *Return: 1
 */

int main(int argc, char *argv[])
{
	unsigned int ln = 1;
	int c = 0;
	size_t bufsize = 1024;
	stack_t *st = NULL;

	if (argc != 2)
	{	fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);	}
	moe.fp = fopen(argv[1], "r");
	if (moe.fp == NULL)
	{	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);	}
	moe.buf = malloc(bufsize * sizeof(char));
	if (moe.buf == NULL)
	{	fprintf(stderr, "Error: malloc failed\n");
		fclose(moe.fp);
		exit(EXIT_FAILURE);	}
	moe.mode = 1;
	while (1)
	{
		c = getline(&moe.buf, &bufsize, moe.fp);
		if (c == EOF)
		{       break;		}
		rmsp(moe.buf);
		if (strcmp(moe.buf, "push") == 0)
			push(&st, ln, strtok(NULL, " "));
		else
		{
			(*c_fn(moe.buf))(&st, ln);
			if (moe.mode == 3)
			{	fprintf(stderr, "L%d: unknown instruction %s\n",
					ln, moe.buf);
				fclose(moe.fp);
				free_stack(&st);
				free(moe.buf);
				exit(EXIT_FAILURE); } }
		ln++;	}
	free(moe.buf);
	free_stack(&st);
	fclose(moe.fp);
	return (0); }
