#include "monty.h"

/**
 * pall_opcode - Prints the elements of a stack
 * @top: Double pointer to the top of the stack
 * @line: The line to be printed
*/

void pall_opcode(stack_t **top, unsigned int line)
{
	stack_t *current;
	(void) line;

	current = *top;

	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
