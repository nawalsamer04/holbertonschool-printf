#include "../main.h"

/**
 * print_number - recursively prints digits of an integer
 * @n: integer to print
 * Return: number of characters printed
 */
static int print_number(int n)
{
	int count = 0;

	if (n / 10)
		count += print_number(n / 10);

	count += _putchar('0' + (n % 10));
	return (count);
}

/**
 * print_int - prints an integer (%d or %i)
 * @ap: va_list with the int to print
 * Return: number of characters printed
 */
int print_int(va_list ap)
{
	int n = va_arg(ap, int);
	int count = 0;

	if (n == 0)
		return (_putchar('0'));

	if (n < 0)
	{
		count += _putchar('-');
		/* handle INT_MIN safely */
		if (n == -2147483648)
		{
			count += _putchar('2');
			n = 147483648;
		}
		else
		{
			n = -n;
		}
	}

	count += print_number(n);
	return (count);
}

