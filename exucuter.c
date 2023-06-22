#include "monty.h"

/**
 * execute_line - executes the operation code as function
 * @head: Double pointer to the stack
 * @op_code: operation code to exec
 * @data: the data next to push
 * @line_number: The line number of the op in the bytecode file
 * Return: 0 if success, 1 if not
 */

int execute_line(stack_t **head, char *op_code,
		char *data, unsigned int line_number)
{
	void (*operation)(stack_t **, unsigned int);

	operation = select_op(op_code);
	if (operation)
	{
		if (strcmp(op_code, "push") == 0)
		{
			if (is_valid_data(data) == ERROR_PUSH)
				return (ERROR_PUSH);
			operation(head, atoi(data));
		}
		else
			operation(head, line_number);

		return (0);
	}
	return (ERROR_INVALID_INSTRC);
}
