#include "main.h"

int main(void)
{
	_printf("Zero: %d\n", 0);
	_printf("Positive: %i\n", 123);
	_printf("Negative: %d\n", -456);
	_printf("INT_MAX: %d\n", 2147483647);
	_printf("INT_MIN: %d\n", -2147483648);
	_printf("Mixed: %s %c %d %%\n", "Hi", 'X', 42);
	return 0;
}
