#include "main.h"

/**
 * print_percent - handle %%
 * @ap: arg list (unused)
 * @b: buffer
 * Return: chars printed or -1
 */
int print_percent(va_list ap, buffer_t *b)
{
	(void)ap;

	if (buf_putc(b, '%') == -1)
		return (-1);
	return (1);
}

