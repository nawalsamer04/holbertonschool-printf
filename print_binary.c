#include "main.h"

/**
 * print_binary - handle %b (unsigned int in binary)
 * @ap: arg list
 * @b: buffer
 * Return: chars printed or -1
 */
int print_binary(va_list ap, buffer_t *b)
{
	unsigned int n = va_arg(ap, unsigned int);
	char tmp[32];
	int i = 0, count = 0;

	if (n == 0)
	{
		if (buf_putc(b, '0') == -1)
			return (-1);
		return (1);
	}

	while (n && i < 32)
	{
		tmp[i++] = (n & 1) ? '1' : '0';
		n >>= 1;
	}

	while (i--)
	{
		if (buf_putc(b, tmp[i]) == -1)
			return (-1);
		count++;
	}
	return (count);
}


