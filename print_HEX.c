#include "main.h"

/**
 * print_HEX - handle %X (hex UPPERCASE)
 * @ap: argument list
 * @b: buffer
 * Return: chars printed or -1
 */
int print_HEX(va_list ap, buffer_t *b)
{
    unsigned int n = va_arg(ap, unsigned int);

    return (print_uint_base(n, 16, "0123456789ABCDEF", b));
}

