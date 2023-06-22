#include "monty.h"


/**
  * main - Entry point
  *
  * @argc: number of args passed to the program
  * @argv: array of arguments passed
  *
  * Return: Always 0
  */

int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	FILE *file;
	char *line = NULL, *op_code = NULL, *data = NULL, *delim = " \t\n";
	unsigned int line_num = 0;
	size_t line_len = 0;
	int status = 0;

	check_num_args(argc);
	file = open_file(argv[1]);

	while (getline(&line, &line_len, file) != -1)
	{
		line_num++;
		op_code = strtok(line, delim);
		if (op_code)
		{
			if (op_code[0] == '#')
				continue;

			data = strtok(NULL, delim);
			status = execute_line(&head, op_code, data, line_num);
			if (status != 0)
			{
				fclose(file);
				error_handler(&head, status, line_num, line, op_code);
			}

		}
	}
	free_stack(&head);
	free(line);
	fclose(file);
	return (0);
}
