#include "main.h"

/**
 * get_spec - dispatch one conversion specifier to its handler
 * @c: the specifier letter
 * @ap: variadic argument list
 * @b: output buffer
 * Return: characters printed, or -1 on error
 */
int get_spec(char c)(va_list ap, buffer_t *b)
{
    int i;
    spec_t table[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'d', print_int},
        {'i', print_int},
        {'b', print_binary},
        {'u', print_unsigned},
        {'o', print_octal},
        {'x', print_hex},
        {'X', print_HEX},
        {'\0', NULL}
    };

    for (i = 0; table[i].sp; i++)
    {
        if (table[i].sp == c)
            return (table[i].fn(ap, b));
    }

    return (-1);
}

