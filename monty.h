#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push_opcode(stack_t **top, unsigned int line);
void pall_opcode(stack_t **top, unsigned int line);
void pint_opcode(stack_t **top, unsigned int line);
void pop_opcode(stack_t **top, unsigned int line);
void swap_opcode(stack_t **top, unsigned int line);
void add_opcode(stack_t **top, unsigned int line);
void freelist(stack_t *top);
void nop_opcode(stack_t **top, unsigned int line);
int execute_opcode(char *input, stack_t **data, unsigned int line, FILE *file);
void insertnode(stack_t **top, int num);
void enqueue_opcode(stack_t **top, int num);

/**
 * struct information - Structure for holding program variables and arguments.
 * @args: Value argument
 * @file: Pointer to monty file
 * @content: Line content
 * @flag: Flag to change between stack and queue behavior
 * Description: Structure that carries values and flags throughout the program
 */
typedef struct information
{
	char *args;
	FILE *file;
	char *content;
	int flag;
} busy_t;

extern busy_t interpreter;

#endif
