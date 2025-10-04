#include "main.h"

/**
 * print_octal - handle %o (octal)
 * @ap: argument list
 * @b: buffer
 * Return: chars printed or -1
 */
int print_octal(va_list ap, buffer_t *b)
{
    unsigned int n = va_arg(ap, unsigned int);

    return (print_uint_base(n, 8, "01234567", b));
}

