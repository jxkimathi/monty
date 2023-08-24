#include "monty.h"

/**
 * swap_opcode - Swaps two elements in a stack
 * @top: Double pointer to the top of the stack
 * @line: The line to be swapped
*/

void swap_opcode(stack_t **top, unsigned int line)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		fclose(interpreter.file);
		free(interpreter.content);
		freelist(*top);
		exit(EXIT_FAILURE);
	}

	current = *top;
	total = current->n;
	current->n = current->next->n;
	current->next->n = total;
}
