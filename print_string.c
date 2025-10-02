#include "main.h"

/**
 * print_string - handle %s
 * @ap: variadic list
 * @b: buffer context
 * Return: number of chars handled, or -1 on error
 * Note: prints "(null)" if the string pointer is NULL.
 */
int print_string(va_list ap, buffer_t *b)
{
	char *s = va_arg(ap, char *);
	int n = 0;

	if (!s)
		s = "(null)";

	while (*s)
	{
		if (buf_putc(b, *s++) == -1)
			return (-1);
		n++;
	}
	return (n);
}

