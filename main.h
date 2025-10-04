#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* ===== buffering ===== */
#define BUFFER_SIZE 1024

/**
 * struct buffer_s - simple output buffer
 * @buf: data
 * @len: bytes currently stored
 */
typedef struct buffer_s
{
	char buf[BUFFER_SIZE];
	int len;
} buffer_t;

int buf_putc(buffer_t *b, char c);
int buf_flush(buffer_t *b);

/* ===== dispatch table ===== */

/**
 * struct spec_s - specifier to handler mapping
 * @sp: specifier character
 * @fn: handler for that specifier
 */
typedef struct spec_s
{
	char sp;
	int (*fn)(va_list, buffer_t *);
} spec_t;

int (*get_spec(char c))(va_list, buffer_t *);

/* ===== core ===== */
int _printf(const char *format, ...);

/* ===== handlers ===== */
int print_char(va_list ap, buffer_t *b);
int print_string(va_list ap, buffer_t *b);
int print_percent(va_list ap, buffer_t *b);
int print_binary(va_list ap, buffer_t *b);

#endif /* MAIN_H */

