#include "monty.h"

/**
 * enqueue_opcode - Adds an element to the queue
 * @top: Double pointer to the top of the queue
 * @num: Value to be added
 */

void enqueue_opcode(stack_t **top, int num)
{
	stack_t *new, *total;

	total = *top;
	new = malloc(sizeof(stack_t));

	if (new == NULL)
		printf("Error\n");

	new->n = num;
	new->next = NULL;

	if (total)
	{
		while (total->next)
			total = total->next;
	}

	if (!total)
	{
		*top = new;
		new->prev = NULL;
	}

	else
	{
		total->next = new;
		new->prev = total;
	}
}
