#include "main.h"

/**
 * print_char - handle %c
 * @ap: variadic list
 * @b: buffer context
 * Return: number of chars handled (1) or -1 on error
 */
int print_char(va_list ap, buffer_t *b)
{
	char c = (char)va_arg(ap, int);

	if (buf_putc(b, c) == -1)
		return (-1);
	return (1);
}

