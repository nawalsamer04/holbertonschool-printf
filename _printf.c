#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * Supported: %c, %s, %d, %i, %u, %%, %b
 * @format: format string
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, count = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
			continue;
		}

		/* handle '%' */
		i++;
		if (format[i] == '\0')
		{
			va_end(ap);
			return (-1); /* stray '%' at end */
		}

		switch (format[i])
		{
		case 'c':
			count += print_char_va(ap);
			break;
		case 's':
			count += print_string_va(ap);
			break;
		case 'd':
		case 'i':
			count += print_number(va_arg(ap, int));
			break;
		case 'u':
			count += print_unsigned(va_arg(ap, unsigned int));
			break;
		case 'b':
			/* هذه الدالة موجودة في print_binary.c */
			count += print_binary(ap);
			break;
		case '%':
			_putchar('%');
			count++;
			break;
		default:
			/* سلوك متوافق مع المشروع: اطبع '%' والحرف كما هو */
			_putchar('%');
			_putchar(format[i]);
			count += 2;
			break;
		}
	}

	va_end(ap);
	return (count);
}

