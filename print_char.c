#include "main.h"

/**
 * print_char - prints a single character for %c
 * @ap: variadic argument list
 * Return: 1 on success, -1 on error
 */
int print_char(va_list ap)
{
	char c = (char)va_arg(ap, int);

	return (_putchar(c));
}

