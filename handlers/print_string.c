#include "main.h"

/**
 * print_string - handle %s
 * @ap: argument list
 * Return: number of chars printed or -1 on error
 */
int print_string(va_list ap)
{
	char *s = va_arg(ap, char *);
	int count = 0;

	if (!s)
		s = "(null)";

	while (*s)
	{
		if (_putchar(*s++) == -1)
			return (-1);
		count++;
	}
	return (count);
}
