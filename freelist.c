#include "monty.h"

/**
 * freelist - Frees a doubly linked list
 * @top: Pointer to the head of the list
 */

void freelist(stack_t *top)
{
	stack_t *total;

	while (top)
	{
		total = top->next;
		free(top);
		top = total;
	}
}
