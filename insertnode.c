#include "monty.h"

/**
 * insertnode - Insert a node at the beginning of a list
 * @top: Double pointer to the head of the stack
 * @num: Value to be inserted
 */

void insertnode(stack_t **top, int num)
{
	stack_t *new, *total;

	total = *top;
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (total)
		total->prev = new;

	new->n = num;
	new->next = *top;
	new->prev = NULL;
	*top = new;
}
