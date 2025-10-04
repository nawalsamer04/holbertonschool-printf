#include "main.h"

/**
 * print_uint_base - print unsigned int in any base using provided digits
 * @n: number
 * @base: base (8, 10, 16, ...)
 * @digits: e.g. "0123456789abcdef"
 * @b: output buffer
 * Return: chars printed, or -1 on error
 */
int print_uint_base(unsigned int n, int base, const char *digits, buffer_t *b)
{
    char buffer[50];
    int i = 0, count = 0;

    if (n == 0)
        return (_putchar('0'));

    while (n)
    {
        buffer[i++] = digits[n % base];
        n /= base;
    }

    while (--i >= 0)
        count += _putchar(buffer[i]);

    return (count);
}

