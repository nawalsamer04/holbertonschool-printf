#include "main.h"

/**
 * print_percent - prints a literal percent sign for %%
 * @ap: variadic argument list (unused)
 * Return: 1 on success, -1 on error
 */
int print_percent(va_list ap)
{
	(void)ap;
	return (_putchar('%'));
}

