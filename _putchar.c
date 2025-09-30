#include "main.h"

/**
 * _putchar - write a single character to stdout
 * @c: character to print
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	ssize_t w = write(1, &c, 1);

	return (w == 1 ? 1 : -1);
}

