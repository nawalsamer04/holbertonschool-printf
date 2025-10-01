#include "../main.h"

/**
 * put_snum - print a signed long integer recursively
 * @n: value
 * Return: number of characters printed
 */
static int put_snum(long n)
{
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}

	if (n / 10)
		count += put_snum(n / 10);

	count += _putchar('0' + (n % 10));

	return (count);
}

/**
 * print_int - handler for %d and %i (signed int)
 * @ap: variadic argument list
 * Return: number of characters printed
 */
int print_int(va_list ap)
{
	long n = (long)va_arg(ap, int);

	return (put_snum(n));
}

