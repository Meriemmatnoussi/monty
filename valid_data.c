#include "monty.h"

/**
 * is_valid_data - Checks if data is valid to push
 *
 * @data: Pointer to the string to be checked.
 *
 * Return: VALID_PUSH or ERROR_PUSH
 */

int is_valid_data(char *data)
{
	if (!data || !digits_check(data))
		return (ERROR_PUSH);
	return (VALID_PUSH);
}




/**
 * digits_check - Checks if a string consists of only digits.
 *
 * @str: Pointer to the string to be checked.
 *
 * Return: true if the string consists of only digits, false otherwise.
 */

bool digits_check(char *str)
{
	for (; *str != '\0'; str++)
	{
		if (str[0] == '-')
			continue;
		if (isdigit(*str) == 0)
			return (false);
	}
	return (true);
}
