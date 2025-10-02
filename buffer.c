#include "main.h"

/**
 * buf_flush - flush buffer to stdout
 * @b: buffer context
 * Return: 0 on success, -1 on write error
 */
int buf_flush(buffer_t *b)
{
	ssize_t w;

	if (b->i <= 0)
		return (0);

	w = write(1, b->buf, b->i);
	if (w < 0)
		return (-1);

	b->i = 0;
	return (0);
}

/**
 * buf_putc - append a char to buffer and flush if full
 * @b: buffer context
 * @c: character to append
 * Return: 0 on success, -1 if flush/write fails
 */
int buf_putc(buffer_t *b, char c)
{
	b->buf[b->i++] = c;
	b->count++;

	if (b->i == (int)sizeof(b->buf))
		return (buf_flush(b));

	return (0);
}

