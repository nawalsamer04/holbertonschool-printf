#include "main.h"

/**
 * print_binary - print an unsigned int in binary (no prefix)
 * @ap: va_list holding the unsigned int
 * Return: number of characters printed
 */
int print_binary(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	char buf[sizeof(unsigned int) * 8];
	int i = 0, count = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n)
	{
		buf[i++] = (n & 1) ? '1' : '0';
		n >>= 1;
	}

	while (i--)
	{
		_putchar(buf[i]);
		count++;
	}
	return (count);
}

