#include "main.h"
/**
* print_char - prints character argument
*
* @print: character to be printed from variadic function
*
* Return: number of byte printed;
*/

int print_char(va_list print)
{
	int byte = 0;

	char c = va_arg(print, int);

	_putchar(c);
	byte++;
	return (byte);
}


/**
* print_string - prints string
*
* @print: string to print from variadic function parameter
*
* Return: printed number of bytes
*/
int print_string(va_list print)
{
	int byte = 0;

	char *str = va_arg(print, char*);

	while (*str)
	{
		_putchar(*str);
		str++;
		byte++;
	}
	return (byte);
}
