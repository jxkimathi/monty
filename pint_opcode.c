#include "monty.h"

/**
 * pint_opcode - Prints the top element of the stack
 * @top: Double pointer to the top of the stack
 * @line: The line to be printed
*/

void pint_opcode(stack_t **top, unsigned int line)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		fclose(interpreter.file);
		free(interpreter.content);
		freelist(*top);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*top)->n);
}
