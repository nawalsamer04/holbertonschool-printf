#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* _putchar.c */
int _putchar(char c);

/* _printf.c */
int _printf(const char *format, ...);

/* print helpers */
int print_char_va(va_list ap);
int print_string_va(va_list ap);
int print_number(int n);
int print_unsigned(unsigned int un);
int print_binary(va_list ap);   /* <<< الإضافة الجديدة */

#endif /* MAIN_H */

