#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string with directives
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

		count += get_spec(*format, ap);
		format++;
	}
	va_end(ap);
	return (count);
}

