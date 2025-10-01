#include "../main.h"

/**
 * print_percent - handler for %% (literal percent)
 * @ap: variadic argument list (unused)
 * Return: 1
 */
int print_percent(va_list ap __attribute__((unused)))
{
	return (_putchar('%'));
}

