#include "monty.h"

/**
 * opcode_exec - checks and executes the opcode.
 * @input: the buffer(file) containing the opcode.
 * @line_no: the line number of the opcode.
 * Return: void.
 */
void opcode_exec(char *input, unsigned int line_no)
{
	instruction_t ops[] = {
		{"pall", pall}, {"push", push}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", div_},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}
	};
	char *token;
	int i;

	input = rem_space(input);
	if (!*input || *input == '#')
		return;
	token = strtok(input, TOK_DELIMETER);
	for (i = 0; i < 13; i++)
	{
		if (strcmp(token, ops[i].opcode) == 0)
		{
			if (strcmp(token, "push") == 0)
			{
				token = strtok(NULL, TOK_DELIMETER);
				is_push(token, line_no);
			}
			ops[i].f(&global.stack, line_no);
			return;
		}
	}
	dprintf(2, "L%u: unknown instruction %s\n", line_no, token);
	clean_exit();
}

/**
 * is_push - checks if the push opcode has been used correctly.
 * @token: the number in string.
 * @line_no: the line number of the opcode in its file.
 */
void is_push(char *token, unsigned int line_no)
{
	if (is_num(token))
		global.num = atoi(token);
	else
	{
		dprintf(2, "L%u: usage: push integer\n", line_no);
		clean_exit();
	}
}
