#include "main.h"

/**
 * print_percent - handle %%
 * @ap: argument list (unused)
 * Return: number of chars printed
 */
int print_percent(va_list ap)
{
	(void)ap;
	return (_putchar('%'));
}

