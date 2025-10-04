#include "main.h"

/**
 * print_unsigned - handle %u (unsigned decimal)
 * @ap: argument list
 * @b: buffer
 * Return: chars printed or -1
 */
int print_unsigned(va_list ap, buffer_t *b)
{
	unsigned int n = va_arg(ap, unsigned int);

	return (print_uint_base(n, 10, "0123456789", b));
}

