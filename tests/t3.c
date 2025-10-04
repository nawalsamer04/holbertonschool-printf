#include "main.h"

/**
 * main - quick tests for %b
 * Return: 0
 */
int main(void)
{
	_printf("%b\n", 98);   /* 1100010 */
	_printf("%b\n", 0);    /* 0 */
	_printf("%b\n", 255);  /* 11111111 */
	return (0);
}
