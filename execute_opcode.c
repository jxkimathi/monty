#include "monty.h"

/**
 * execute_opcode - Executes the opcodes
 * @data: Double pointer to the data
 * @line: The line to be executed
 * @file: A pointer to the file
 * @input: Input received by the user
 *
 * Return: 1 upon failure, 0 upon success
 */

int execute_opcode(char *input, stack_t **data, unsigned int line, FILE *file)
{
	instruction_t ops[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
		{"pint", pint_opcode},
		{"pop", pop_opcode},
		{"swap", swap_opcode},
		{"add", add_opcode},
		{"nop", nop_opcode},
		{NULL, NULL}
	};
	unsigned int index = 0;
	char *op;

	op = strtok(input, "\n\t");

	if (op && op[0] == '#')
		return (0);

	interpreter.args = strtok(NULL, "\n\t");

	while (ops[index].opcode && op)
	{
		if (strcmp(op, ops[index].opcode) == 0)
		{
			ops[index].f(data, line);
			return (0);
		}
		index++;
	}

	if (op && ops[index].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, op);
		fclose(file);
		free(input);
		freelist(*data);
		exit(EXIT_FAILURE);
	}

	return (1);
}
