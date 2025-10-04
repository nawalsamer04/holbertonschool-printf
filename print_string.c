#include "main.h"

/**
 * print_string - handle %s
 * @ap: arg list
 * @b: buffer
 * Return: chars printed or -1
 */
int print_string(va_list ap, buffer_t *b)
{
	char *s = va_arg(ap, char *);
	int count = 0;

	if (!s)
		s = "(null)";

	while (*s)
	{
		if (buf_putc(b, *s++) == -1)
			return (-1);
		count++;
	}
	return (count);
}

