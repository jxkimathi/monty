#include "monty.h"

/**
 * push_opcode - Pushes an element on the stack
 * @top: Double pointer to the top of the stack
 * @line: Line to be pushed
*/

void push_opcode(stack_t **top, unsigned int line)
{
	int num, i = 0, cust = 0;

	if (interpreter.args)
	{
		if (interpreter.args[0] == '-')
			i++;

		for (; interpreter.args[0] != '\0'; i++)
		{
			if (interpreter.args[i] > 57 || interpreter.args[i] < 48)
				cust = 1;
		}

		if (cust == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			fclose(interpreter.file);
			free(interpreter.content);
			freelist(*top);
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		fprintf(stderr, "L%d: usage push integer\n", line);
		fclose(interpreter.file);
		free(interpreter.content);
		freelist(*top);
		exit(EXIT_FAILURE);
	}

	num = atoi(interpreter.args);

	if (interpreter.flag == 0)
		insertnode(top, num);

	else
		enqueue_opcode(top, num);
}
