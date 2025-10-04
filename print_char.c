#include "main.h"

/**
 * print_char - handle %c
 * @ap: arg list
 * @b: buffer
 * Return: chars printed or -1
 */
int print_char(va_list ap, buffer_t *b)
{
	char c = (char)va_arg(ap, int);

	if (buf_putc(b, c) == -1)
		return (-1);
	return (1);
}

