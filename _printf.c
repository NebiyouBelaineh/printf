#include "main.h"
#include <stdarg.h>
#include <stdio.h>

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
	char chr;
	int (*fun_pt)(va_list);


	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			chr = *format;
			fun_pt = get_func(chr);
			if (fun_pt != NULL)
				byte += fun_pt(print);
			else
				return (-1);
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

	/*if (format == NULL || ((*format == '%') && *(format + 1) == '\0'))*/
		/*return (-1);*/
	/*if (*format == '%' && *(format + 1) == ' ' && *(format + 2) == '\0')*/
		/*return (-1);*/
	va_start(print, format);
	if (format == NULL || print == NULL)
		return (-1);
	bytes = print_arg(print, format);
	if (bytes < 0)
	{
		va_end(print);
		return (bytes);
	}
	va_end(print);
	return (bytes);
}
