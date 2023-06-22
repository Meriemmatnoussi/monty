#include "monty.h"

void print_error(char *fileName);

/**
 * open_file - a function that opens a file and checks its existens
 * @fileName: a file name or a path
 * Return: The opened file
 */

FILE *open_file(char *fileName)
{
	FILE *file = NULL;

	if (access(fileName, R_OK) == -1)
		print_error(fileName);

	file = fopen(fileName, "r");

	if (!file)
		print_error(fileName);

	return (file);
}

/**
 * print_error - prints an error message and exits the program
 * @fileName: a file name
 * Return: Nothing
 */

void print_error(char *fileName)
{

	fprintf(stderr, "Error: Can't open file %s\n", fileName);
	exit(EXIT_FAILURE);
}
