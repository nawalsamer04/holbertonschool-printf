#include "main.h"
/**
 * dispatch - route to the correct handler function
 * @c: specifier character following '%'
 * @ap: variadic argument list
 * Return: characters printed by the handler,
 *         or 2 if printing unknown as "%<c>"
 */

static int dispatch(char c, va_list ap)
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
/**
 * _printf - produces output according to a format
 * @format: format string (supports %c, %s, %%, %d, %i)
 * Return: number of characters printed, or -1 on error
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0;

	if (!format)
		return (-1);

	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
			format++;
			continue;
		}
		format++;
		if (!*format)
		{
			va_end(ap);
			return (-1);
		}
		count += dispatch(*format, ap);
		format++;
	}
	va_end(ap);
	return (count);
}

