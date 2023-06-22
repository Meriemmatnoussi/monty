#include "monty.h"

/**
 * check_num_args - checks the number of args passed to the program
 * @argc: number of args
 * Return: Nothing
 */

void check_num_args(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
