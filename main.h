#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h> /* for NULL */

/**
 * struct spec_s - specifier map
 * @sp: specifier character (like 'c', 'd', etc)
 * @fn: function pointer to handler
 */
typedef struct spec_s
{
	char sp;
	int (*fn)(va_list);
} spec_t;

/* Core */
int _printf(const char *format, ...);
int _putchar(char c);

/* Task 0 Handlers */
int print_char(va_list ap);
int print_string(va_list ap);
int print_percent(va_list ap);

/* Task 1 Handler */
int print_int(va_list ap);
int get_spec(char c, va_list ap);
#endif /* MAIN_H */


