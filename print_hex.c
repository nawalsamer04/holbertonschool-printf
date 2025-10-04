#include "main.h"

/**
 * print_hex - handle %x (hex lowercase)
 * @ap: argument list
 * @b: buffer
 * Return: chars printed or -1
 */
int print_hex(va_list ap, buffer_t *b)
{
    unsigned int n = va_arg(ap, unsigned int);

    return (print_uint_base(n, 16, "0123456789abcdef", b));
}

