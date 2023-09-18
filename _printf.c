#include "main.h"
/**
* print_char - prints arguments for printf function
*
* @print: variadic function parameter
* @format: format specifier
*
* Return: number of printed bytes
*/
int print_char(va_list print, const char *format)
{
	int byte = 0;
	char chr, c;
	char *str;

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
					_putchar(c);
					byte++;
					break;
				case 's':
					str = va_arg(print, char*);
					while (*str)
					{
						_putchar(*str);
						str++;
						byte++;
					}
					break;
			}
		}
		else
		{
			putchar(*format);
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

	if (format == NULL)
		return (-1);

	va_start(print, format);
	bytes = print_char(print, format);
	va_end(print);
	return (bytes);
}
