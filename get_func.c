#include "main.h"
/**
 * get_func - gets the right function to use depending on the
 * conversion specifier
 *
 * @specifier: convsersion specifier passed to get_func
 *
 * Return: appropriate function along with respective return value.
*/
int (*get_func(char specifier))(va_list print)
{
	prt_func func_print[] = {
		{'i', _print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', _print_int},
		{'%', print_percent}
	};
	int i, size = 5;

	for (i = 0; i < size; i++)
		if (func_print[i].symbol == specifier)
			return (func_print[i].fun_pt);

	return (NULL);
}
