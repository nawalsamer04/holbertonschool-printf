#include "main.h"

/**
 * get_spec - return handler for a specifier
 * @c: specifier character
 * Return: function pointer or NULL
 */
int (*get_spec(char c))(va_list, buffer_t *)
{
	static spec_t table[] = {
		{ 'c', print_char },
		{ 's', print_string },
		{ '%', print_percent },
		{ 'b', print_binary },
		{ '\0', NULL }
	};
	int i;

	for (i = 0; table[i].sp; i++)
	{
		if (table[i].sp == c)
			return (table[i].fn);
	}
	return (NULL);
}

