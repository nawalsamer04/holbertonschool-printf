#include "main.h"

/**
 * process_format - walk the format string and print
 * @format: format string
 * @ap: arg list
 * @b: buffer
 * Return: count or -1 on error
 */
static int process_format(const char *format, va_list ap, buffer_t *b)
{
	int i = 0, count = 0;
	int (*fn)(va_list, buffer_t *);

	while (format[i])
	{
		if (format[i] != '%')
		{
			if (buf_putc(b, format[i]) == -1)
				return (-1);
			count++;
		}
		else
		{
			i++;
			if (!format[i])
				return (-1);

			fn = get_spec(format[i]);
			if (fn)
			{
				int n = fn(ap, b);

				if (n == -1)
					return (-1);
				count += n;
			}
			else
			{
				if (buf_putc(b, '%') == -1 || buf_putc(b, format[i]) == -1)
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
 * Return: number printed or -1
 */
int _printf(const char *format, ...)
{
	va_list ap;
	buffer_t buf = {{0}, 0};
	int count;

	if (!format)
		return (-1);

	va_start(ap, format);
	count = process_format(format, ap, &buf);
	va_end(ap);

	if (count != -1 && buf_flush(&buf) == -1)
		return (-1);
	return (count);
}

