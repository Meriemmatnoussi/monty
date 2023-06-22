#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the command in the source file
 *
 * Return: Nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *tmp = *stack;

	(void) line_number;

	if (!(*stack))
	{
		printf("\n");
		return;
	}

	while (tmp)
	{
		n = tmp->n;
		if (n == 0 || n < 0 || n > 127)
		{
			printf("\n");
			return;
		}

		tmp = tmp->next;

		printf("%c", n);
	}
	printf("\n");
}
