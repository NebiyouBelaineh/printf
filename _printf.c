#include "main.h"
#include <stdio.h>
#include <stdarg.h>


/**
 * print_char - prints character argument
 *
 * @c: character to be printed
 *
 * Return: void;
*/

void print_char(char c)
{
	_putchar(c);
}


/**
 * print_string - prints string
 *
 * @str: string to print
 *
 * Return: printed number of bytes
*/
int print_string(const char *str)
{
	int byte = 0;

	while (*str)
	{
		_putchar(*str);
		str++;
		byte++;
	}
	return (byte);
}
/**
* print_arg - prints arguments for printf function
*
* @print: variadic function parameter
* @format: format specifier
*
* Return: number of printed bytes
*/
int print_arg(va_list print, const char *format)
{
	int byte = 0/*,num*/;
	char chr, c;
	const char *str;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			chr = *format;
			switch (chr)
			{
				case '%':
					_putchar(chr);
					byte++;
					break;
				case 'c':
					c = va_arg(print, int);
					print_char(c);
					byte++;
					break;
				case 's':
					str = va_arg(print, const char*);
					if (str == NULL)
						return (-1);
					byte += print_string(str);
					break;
				default:
					return (-1);
			}
		}
		else
		{
			_putchar(*format);
			byte++;
		}
		format++;
	}
	return (byte);
}

/**
* _printf - writes formated output to stdout
* @format: format specifier
*
* Return: number of bytes written
*/

int _printf(const char *format, ...)
{
	va_list print;
	int bytes = 0;

	if (format == NULL || ((*format == '%') && *(format + 1) == '\0'))
		return (-1);
	if (*format == '%' && *(format + 1) == ' ' && *(format + 2) == '\0')
		return (-1);

	va_start(print, format);
	bytes = print_arg(print, format);
	va_end(print);
	return (bytes);
}
