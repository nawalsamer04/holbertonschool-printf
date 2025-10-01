#include "../main.h"

/**
 * print_string - handler for %s (C string)
 * @ap: variadic argument list
 * Return: number of characters printed
 */
int print_string(va_list ap)
{
	char *s = va_arg(ap, char *);
	int len = 0;

	if (!s)
		s = "(null)";

	while (s[len])
	{
		_putchar(s[len]);
		len++;
	}

	return (len);
}

