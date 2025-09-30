#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Core */
int _printf(const char *format, ...);
int _putchar(char c);

/* Task 0 handlers */
int print_char(va_list ap);
int print_string(va_list ap);
int print_percent(va_list ap);

#endif /* MAIN_H */

