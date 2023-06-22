#include "monty.h"

/**
 * sub - subtracts the top two elements of the stack
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the command in the source file
 *
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	int sum = 0;

	if (!(*stack) || !(*stack)->next)
		error_handler(stack, ERROR_SUB, line_number, NULL, NULL);
	top = *stack;
	second = (*stack)->next;
	sum = second->n - top->n;
	second->n = sum;

	top->next = second->next;
	free(top);
	*stack = second;
}
