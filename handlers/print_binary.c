#include "main.h"

/**
 * print_binary - handle %b (unsigned int to binary)
 * @ap: argument list
 * Return: number of chars printed, or -1 on error
 */
int print_binary(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	char buf[32];
	int i = 0, count = 0;

	if (n == 0)
		return (_putchar('0'));

	while (n > 0 && i < 32)
	{
		buf[i++] = (n & 1) ? '1' : '0';
		n >>= 1;
	}

	while (i--)
	{
		if (_putchar(buf[i]) == -1)
			return (-1);
		count++;
	}
	return (count);
}
