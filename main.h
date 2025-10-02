#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct buffer_s - local buffered output (no globals)
 * @buf: data area
 * @i:   current index in buf
 * @count: total characters accounted for output
 */
typedef struct buffer_s
{
	char buf[1024];
	int i;
	int count;
} buffer_t;

/* Core */
int _printf(const char *format, ...);

/* Buffered I/O helpers */
int buf_putc(buffer_t *b, char c);
int buf_flush(buffer_t *b);

/* Handlers (updated signatures to use buffer) */
int print_char(va_list ap, buffer_t *b);
int print_string(va_list ap, buffer_t *b);
int print_percent(va_list ap, buffer_t *b);

#endif /* MAIN_H */

