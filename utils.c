#include "monty.h"

/**
 * is_nan - is not a number
 * @str: the string to check
 *
 * Return: 1 if not a number, o if number
 */
int is_nan(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
		{
			i++;
			continue;
		}
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
