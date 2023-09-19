#include "main.h"

/**
* print_int - Prints integers using %d or %i
*
*@n: Number to be printed
*
* Return: printed number of bytes
*/
int print_int(unsigned int n)
{
	int i = 0, count, num;

	char str[__INT_MAX__];

	num = n;

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

/**
* get_binary - returns the binary version of an unsigned int
*
* @num: number we want to find the binary version of
*
* Return: binary format of num
*/
unsigned int get_binary(unsigned int num)
{
	if (num == 0 || num == 1)
		return (num);
	else
		return ((num % 2) + 10 * get_binary(num / 2));
}
/**
* print_binary - prints the binary version of an unsigned int
*
* @print: variadic function parameter
*
* Return: byte;
*/
int print_binary(va_list print)
{
	unsigned int n, byte = 0;

	/*if (va_arg(print, int) < 0)*/
		/*return (-1);*/
	n = va_arg(print, int);

	n = get_binary(n);
	byte += print_int(n);
	return (byte);
}
