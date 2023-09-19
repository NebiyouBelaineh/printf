#include "main.h"
/**
 *_print_int - Prints integers using %d or %i
 *
 *@print: Number to be printed from variadic function parameter
 *
 * Return: printed number of bytes
 */
int _print_int(va_list print)
{
	int i = 0, count, num;
	char str[65535];

	num = va_arg(print, int);

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while (num != 0);
	count = i;
	while (i > 0)
		_putchar(str[--i]);
	return (count);
}
