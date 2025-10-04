#include "main.h"

/**
 * process_format - walk the format string and print
 * @format: format string
 * @ap: variadic arguments
 * Return: number of chars printed, or -1 on error
 */
static int process_format(const char *format, va_list ap)
{
	int i = 0, count = 0;
	int (*f)(va_list);

	while (format[i])
	{
		if (format[i] != '%')
		{
			if (_putchar(format[i]) == -1)
				return (-1);
			count++;
		}
		else
		{
			i++;
			if (!format[i])
				return (-1);

			f = get_spec(format[i]);
			if (f)
			{
				int n = f(ap);

				if (n == -1)
					return (-1);
				count += n;
			}
			else
			{
				if (_putchar('%') == -1 || _putchar(format[i]) == -1)
					return (-1);
				count += 2;
			}
		}
		i++;
	}
	return (count);
}

/**
 * _printf - minimal printf supporting c, s, %, b
 * @format: format string
 * Return: number of chars printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count;

	if (!format)
		return (-1);

	va_start(ap, format);
	count = process_format(format, ap);
	va_end(ap);

	return (count);
}

