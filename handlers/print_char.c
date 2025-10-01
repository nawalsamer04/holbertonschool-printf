#include "../main.h"

/**
 * print_char - handler for %c (character)
 * @ap: variadic argument list
 * Return: number of characters printed (1) or -1 on error
 */
int print_char(va_list ap)
{
	char c = (char)va_arg(ap, int);

	return (_putchar(c));
}


