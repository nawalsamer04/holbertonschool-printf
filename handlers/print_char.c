#include "main.h"

/**
 * print_char - handle %c
 * @ap: argument list
 * Return: number of chars printed
 */
int print_char(va_list ap)
{
	char c = (char)va_arg(ap, int);

	return (_putchar(c));
}
