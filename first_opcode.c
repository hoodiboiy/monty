#include "monty.h"

/**
 * push - pushes an element onto the stack.
 * @head: ptr to the head of the stack.
 * @line_no: the line of the opcode being executed.
 * Return: void.
 */
void push(stack_t **head, unsigned int line_no)
{
	stack_t *top;

	(void)line_no;
	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		clean_exit();
	}
	top->prev = NULL;
	top->n = global.num;
	top->next = *head;
	if (*head != NULL)
		(*head)->prev = top;
	*head = top;
}

/**
 * pall - prints all stack elements.
 * @head: ptr to the head of the stack.
 * @line_no: the line of the opcode being executed.
 * Return: void.
 */
void pall(stack_t **head, unsigned int line_no)
{
	stack_t *top;

	(void)line_no;
	if (*head == NULL || head == NULL)
		return;
	top = *head;
	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}

/**
 * pint - prints top stack element.
 * @head: the head of the stack.
 * @line_no: the line number of the opcode being executed.
 * Return: void.
 */
void pint(stack_t **head, unsigned int line_no)
{
	stack_t *top;

	(void)line_no;
	if (*head == NULL || head == NULL)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_no);
		clean_exit();
	}
	top = *head;
	printf("%d\n", top->n);
}

/**
 * pop - removes top most element from stack.
 * @head: the head of the stack.
 * @line_no: the line number of the opcode being executed.
 * Return: void.
 */
void pop(stack_t **head, unsigned int line_no)
{
	stack_t *top;

	if (*head == NULL || head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_no);
		clean_exit();
	}
	top = *head;
	*head = top->next;
	if (*head)
		(*head)->prev = NULL;
	free(top);
}

/**
 * swap - swaps 2 topmost stack elements.
 * @head: the head of the stack.
 * @line_no: the line of the opcode being executed.
 * Return: void.
 */
void swap(stack_t **head, unsigned int line_no)
{
	stack_t *top;
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_no);
		clean_exit();
	}
	top = *head;
	temp = top->n;
	top->n = top->next->n;
	top->next->n = temp;
}
