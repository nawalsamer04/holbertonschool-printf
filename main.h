#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
/**
 * struct spec_s - specifier map
 * @sp: specifier character
 * @fn: handler function
 */

typedef struct spec_s
{
	char sp;
	int (*fn)(va_list);
} spec_t;

int _printf(const char *format, ...);

/* Task 0 */
int print_char(va_list ap);
int print_string(va_list ap);
int print_percent(va_list ap);

/* Task 1 */
int print_int(va_list ap);

int _putchar(char c);

#endif

