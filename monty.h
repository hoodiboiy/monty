#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
#define TOK_DELIMETER " \t\r\n\a"
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
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
 * struct glob_vars - global variables
 * @num: number to initailise linked list with.
 * @file_ptr: file pointer.
 * @stack: the stack.
 * @line: the line containing opcodes.
 */
typedef struct glob_vars
{
	int num;
	FILE *file_ptr;
	stack_t *stack;
	char *line;
} g_var;
extern g_var global;

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
	void (*f)(stack_t **stack, unsigned int line_no);
} instruction_t;

void pall(stack_t **head, unsigned int line_no);
void opcode_exec(char *input, unsigned int line_no);
void push(stack_t **head, unsigned int line_no);
void pint(stack_t **head, unsigned int line_no);
void pop(stack_t **head, unsigned int line_no);
void swap(stack_t **head, unsigned int line_no);
void add(stack_t **head, unsigned int line_no);
void sub(stack_t **head, unsigned int line_no);
void div_(stack_t **head, unsigned int line_no);
void mul(stack_t **head, unsigned int line_no);
void mod(stack_t **head, unsigned int line_no);
void nop(stack_t **head, unsigned int line_no);
void pchar(stack_t **head, unsigned int line_no);
void pstr(stack_t **head, unsigned int line_no);

void clean_exit(void);
void free_stack(stack_t *head);
void is_push(char *tok, unsigned int line_no);
char *rem_space(char *str);
int is_num(char *str);
#endif /* MONTY_H */
