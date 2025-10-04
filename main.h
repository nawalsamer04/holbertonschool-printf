#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct buffer_s - simple output buffer
 * @data: pointer to array
 * @len: number of bytes currently stored
 */
typedef struct buffer_s
{
	char *data;
	int len;
} buffer_t;

/**
 * struct spec_s - specifier map
 * @sp: specifier character
 * @fn: handler function
 */
typedef struct spec_s
{
	char sp;
	int (*fn)(va_list, buffer_t *);
} spec_t;

/* prototypes … */
int print_unsigned(va_list ap, buffer_t *b);
int print_octal(va_list ap, buffer_t *b);
int print_hex(va_list ap, buffer_t *b);
int print_HEX(va_list ap, buffer_t *b);
int print_uint_base(unsigned int n, unsigned int base,
		    const char *digits, buffer_t *b);

int get_spec(char c, va_list ap, buffer_t *b);
int print_uint_base(unsigned int n, int base, const char *digits, buffer_t *b);

#endif /* MAIN_H */

