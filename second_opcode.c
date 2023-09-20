#include "monty.h"

/**
 * add - adds 2 topmost stack elements.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void add(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (*head == NULL || !(*head)->next || head == NULL)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_num);
		clean_exit();
	}
	top = *head;
	(*head)->next->n += (*head)->n;
	*head = top->next;
	if (*head)
		(*head)->prev = NULL;
	free(top);
}

/**
 * sub - adds 2 topmost stack elements.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void sub(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (*head == NULL || !(*head)->next || head == NULL)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_num);
		clean_exit();
	}
	top = *head;
	(*head)->next->n -= (*head)->n;
	*head = top->next;
	if (*head)
		(*head)->prev = NULL;
	free(top);
}

/**
 * div - adds 2 topmost stack elements.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void div_(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (*head == NULL || !(*head)->next)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_num);
		clean_exit();
	}
	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_num);
		clean_exit();
	}
	top = *head;
	(*head)->next->n /= (*head)->n;
	*head = top->next;
	if (*head)
		(*head)->prev = NULL;
	free(top);
}

/**
 * mul - adds 2 topmost stack elements.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void mul(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (*head == NULL || !(*head)->next)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_num);
		clean_exit();
	}
	top = *head;
	(*head)->next->n *= (*head)->n;
	*head = top->next;
	if (*head)
		(*head)->prev = NULL;
	free(top);
}

/**
 * nop - does nothing.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void nop(stack_t **head, __attribute__((unused))unsigned int line_num)
{
	(void)head;
}
