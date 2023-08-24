#include "monty.h"
#include <stdio.h>
busy_t interpreter = {NULL, NULL, NULL, 0};

/**
 * main - The Monty code interpreter
 * @argv: The argument name
 * @argc: The number of arguments
 *
 * Return: 0 upon success, 1 upon failure
 */

int main(int argc, char *argv[])
{
	char *content;
	FILE *newfile;
	size_t size = 0;
	ssize_t readline = 1;
	stack_t *newstack = NULL;
	unsigned int line = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	newfile = fopen(argv[1], "r");
	interpreter.file = newfile;

	if (!newfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (readline > 0)
	{
		content = NULL;
		readline = getline(&content, &size, newfile);
		interpreter.content = content;
		line++;

		if (readline > 0)
			execute_opcode(content, &newstack, line, newfile);

		free(content);
	}

	freelist(newstack);
	fclose(newfile);

	return (0);
}
