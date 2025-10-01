#include "main.h"

/**
 * get_spec - dispatch to the proper handler for a specifier
 * @c: specifier character
 * @ap: variadic argument list
 * Return: number of characters printed
 */
int get_spec(char c, va_list ap)
{
	spec_t table[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL}
	};
	int i = 0;

	while (table[i].sp)
	{
		if (table[i].sp == c)
			return (table[i].fn(ap));
		i++;
	}

	_putchar('%');
	_putchar(c);
	return (2);
}

