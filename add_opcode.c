#include "monty.h"

/**
 * add_opcode - Adds the top two elements of the stack
 * @top: Pointer to the top of the stack
 * @line: Line number
*/

void add_opcode(stack_t **top, unsigned int line)
{
	stack_t *current;
	int length = 0, total;

	current = *top;

	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		fclose(interpreter.file);
		free(interpreter.content);
		freelist(*top);
		exit(EXIT_FAILURE);
	}

	current = *top;
	total = current->n + current->next->n;
	current->next->n = total;
	*top = current->next;
	free(current);
}
