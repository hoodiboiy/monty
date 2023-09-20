#include "monty.h"

/**
 * free_stack - frees a doubly linked list.
 * @head: pointer to the top of the stack.
 * Return: void.
 */
void free_stack(stack_t *head)
{
	stack_t *top;

	while (head)
	{
		top = head;
		head = head->next;
		free(top);
	}
}

/**
 * rem_space - removes leading and trailing whitespace from a string.
 * @str: pointer to the string.
 * Return: pointer to the trimmed string.
 */
char *rem_space(char *str)
{
	char *end;

	while (isspace((unsigned char)*str))
		str++;

	if (*str == '\0')
		return (str);

	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*str))
		end--;

	*(end + 1) = '\0';
	return (str);
}

/**
 * is_num - checks if a string, @str is a number.
 * @str: the string.
 * Return: if it's a number return 1 else, 0.
 */
int is_num(char *str)
{
	if (!str || *str == '\0')
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	if (*str == '\0')
		return (0);

	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * clean_exit - frees all memory and exits with a failed stauts.
 * Return: void.
 */
void clean_exit(void)
{
	fclose(global.file_ptr);
	free_stack(global.stack);
	free(global.line);
	exit(EXIT_FAILURE);
}
