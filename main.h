#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* public API */
int _printf(const char *format, ...);
int _putchar(char c);

/* %b handler (implementation in print_binary.c) */
int print_binary(va_list ap);

#endif /* MAIN_H */

