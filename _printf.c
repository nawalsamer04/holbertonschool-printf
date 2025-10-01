#include "main.h"
#include <stdarg.h>

/* ==== Helpers (static) ==== */

/**
 * print_number - prints a signed integer using _putchar
 * @n: number to print
 * Return: count of printed characters
 */
static int print_number(int n)
{
	int count = 0;
	unsigned int un;

	if (n < 0)
	{
		_putchar('-');
		count++;
		un = (unsigned int)(-n);
	}
	else
	{
		un = (unsigned int)n;
	}

	/* print unsigned part recursively */
	if (un / 10)
		count += print_number((int)(un / 10));
	_putchar((un % 10) + '0');
	return (count + 1);
}

/**
 * print_unsigned - prints an unsigned int in base 10
 * @un: unsigned number
 * Return: count of printed characters
 */
static int print_unsigned(unsigned int un)
{
	int count = 0;

	if (un / 10)
		count += print_unsigned(un / 10);
	_putchar((un % 10) + '0');
	return (count + 1);
}

/**
 * print_binary_va - prints an unsigned int in binary (no prefix)
 * @ap: va_list positioned at the argument
 * Return: count of printed characters
 */
static int print_binary_va(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	char buf[sizeof(unsigned int) * 8];
	int i = 0, count = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n)
	{
		buf[i++] = (n & 1) ? '1' : '0';
		n >>= 1;
	}
	while (i--)
	{
		_putchar(buf[i]);
		count++;
	}
	return (count);
}

/**
 * print_string_va - prints a C-string from va_list
 * @ap: va_list
 * Return: count of printed characters
 */
static int print_string_va(va_list ap)
{
	char *s = va_arg(ap, char *);
	int count = 0;

	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		_putchar(*s++);
		count++;
	}
	return (count);
}

/**
 * print_char_va - prints a char from va_list
 * @ap: va_list
 * Return: 1
 */
static int print_char_va(va_list ap)
{
	char c = (char)va_arg(ap, int);

	_putchar(c);
	return (1);
}

/* ==== Public API ==== */

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
			/* stray '%' at end -> error per project convention */
			va_end(ap);
			return (-1);
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
		case 'b': /* <<< المطلوب */
			count += print_binary_va(ap);
			break;
		case '%':
			_putchar('%');
			count++;
			break;
		default:
			/* سلوك متوافق: اطبع الحرفين كما هما */
			_putchar('%');
			_putchar(format[i]);
			count += 2;
			break;
		}
	}

	va_end(ap);
	return (count);
}

