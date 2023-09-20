#include "monty.h"
g_var global = {0, NULL, NULL, NULL};

/**
 * main - An interpreter for monty bytecodes.
 * @argc: argument count to program.
 * @argv: arguments list to program.
 * Return: always 0.
 */
int main(int argc, char *argv[])
{
	size_t len = 0;
	int line_no = 1;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global.file_ptr = fopen(argv[1], "r");
	if (global.file_ptr == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&(global.line), &len, global.file_ptr) != -1)
	{
		opcode_exec(global.line, line_no);
		line_no++;
	}
	fclose(global.file_ptr);
	free_stack(global.stack);
	free(global.line);
	return (0);
}
