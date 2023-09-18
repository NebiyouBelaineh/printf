#include "main.h"
/**
 *_print_int - Prints integers using %d or %i
 *
 *@num: Number to be printed
 *
 * Return: printed number of bytes
 */
int _print_int(int num)
{
	int i = 0, count;
	char str[2000];

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
