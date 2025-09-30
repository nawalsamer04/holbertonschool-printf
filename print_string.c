#include "main.h"

/**
 * print_string - prints a C-string for %s
 * @ap: variadic argument list
 * Return: printed length or -1 on error
 * Note: prints "(null)" if string pointer is NULL.
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

