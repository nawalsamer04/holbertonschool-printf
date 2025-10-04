#include "main.h"

/**
 * buf_putc - append one char to buffer, flushing if full
 * @b: buffer
 * @c: character
 * Return: 1 on success, -1 on write error
 */
int buf_putc(buffer_t *b, char c)
{
	if (b->len >= BUFFER_SIZE)
	{
		if (buf_flush(b) == -1)
			return (-1);
	}
	b->buf[b->len++] = c;
	return (1);
}

/**
 * buf_flush - write buffered bytes to stdout
 * @b: buffer
 * Return: bytes written, or -1 on error
 */
int buf_flush(buffer_t *b)
{
	ssize_t w;

	if (b->len == 0)
		return (0);

	w = write(1, b->buf, b->len);
	if (w == -1)
		return (-1);

	b->len = 0;
	return ((int)w);
}
