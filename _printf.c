#include "main.h"

/**
 * dispatch - route specifier to handler
 * @sp: specifier character
 * @ap: variadic list
 * @b: buffer context
 * Return: chars handled by the spec,  -1 on error
 */
static int dispatch(char sp, va_list ap, buffer_t *b)
{
	int n = -1;

	switch (sp)
	{
	case 'c':
		n = print_char(ap, b);
		break;
	case 's':
		n = print_string(ap, b);
		break;
	case '%':
		n = print_percent(ap, b);
		break;
	default:
		/* Unknown: print '%' then the character */
		if (buf_putc(b, '%') == -1 || buf_putc(b, sp) == -1)
			return (-1);
		n = 2;
		break;
	}
	return (n);
}

/**
 * _printf - minimal printf supporting %c, %s and %%
 *           using a local 1024-byte buffer
 * @format: format string
 * Return: total printed characters, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	buffer_t buf = {{0}, 0, 0};
	int i = 0, r;

	if (!format)
		return (-1);

	va_start(ap, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
			if (buf_putc(&buf, format[i]) == -1)
			{
				va_end(ap);
				return (-1);
			}
			i++;
			continue;
		}

		i++; /* skip '%' */
		if (!format[i]) /* lone '%' at end -> error */
		{
			va_end(ap);
			return (-1);
		}

		r = dispatch(format[i], ap, &buf);
		if (r == -1)
		{
			va_end(ap);
			return (-1);
		}
		i++;
	}

	/* flush any remaining bytes */
	if (buf_flush(&buf) == -1)
	{
		va_end(ap);
		return (-1);
	}

	va_end(ap);
	return (buf.count);
}

