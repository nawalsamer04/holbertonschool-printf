#include "main.h"

/**
 * _putchar - write one character to stdout
 * @c: character to print
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

