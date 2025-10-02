#include "main.h"

/**
 * print_percent - handle %%
 * @ap: variadic list (unused)
 * @b: buffer context
 * Return: 1 on success, -1 on error
 */
int print_percent(va_list ap, buffer_t *b)
{
	(void)ap;
	if (buf_putc(b, '%') == -1)
		return (-1);
	return (1);
}

