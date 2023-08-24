#include "monty.h"

/**
 * pop_opcode - Print from the top of the stack
 * @top: Double pointer to top of the stack
 * @line: Line to be printed
*/

void pop_opcode(stack_t **top, unsigned int line)
{
	stack_t *current;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		fclose(interpreter.file);
		free(interpreter.content);
		freelist(*top);
		exit(EXIT_FAILURE);
	}

	current = *top;
	*top = current->next;
	free(current);
}
