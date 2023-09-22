#include "main.h"

/**
* print_arg - Finds appropriate function according to format specifier
*
* @format: Format specifier
* @func_print: Struct holding appropriate function for conversion
* specifiers
* @buffer: Buffer needed to copy
* @buf_lenptr: Pointer to the length of the buffer
* @buf_posptr: Pointer to the position within the buffer
* @print: va_list to retrieve all arguments to _printf function
*
* Return: Return the number of characters written to stdout
*/

int print_arg(const char *format, va_list print, char buffer[],
		  int *buf_lenptr, int *buf_posptr, prt_func func_print[])
{
	int n, bytes, count, *track;

	track = &n;

	bytes = 0;
	for (n = 0; format[n] != '\0' && format != NULL; n++)
	{
		count = 0;
		if (format[n] == '%')
		{
			++n;
			if (format[n] != '%')
			count += get_func(format, track, func_print, buffer,
			 buf_lenptr, buf_posptr, print);
			else
				count += buffer_copy(format[n], buffer, buf_lenptr,
				buf_posptr);
		}
		else
		{
			count += buffer_copy(format[n], buffer, buf_lenptr,
						buf_posptr);
		}
		bytes += count;
	}
	return (bytes);
}

/**
* _printf - Writes formatted output stdout
*
* @format: format specifier
*
* Return: number of bytes written
*/

int _printf(const char *format, ...)
{
	va_list print;
	char buffer[1024];
	int bytes, buf_len, buf_pos, *buf_lenptr, *buf_posptr;

	prt_func func_print[] = {
		{'c', print_char},
		{'s', print_string},
		{'i', _print_int},
		{'d', _print_int},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hex},
		{'X', print_HEX},
		{'b', bi_print},
		{'r', print_reverse},
		{'R', print_rot13},
		{'p', print_pointer},
		{'S', print_Special},
		};
	if (format == NULL)
		return (0);

	init_buffer(buffer);
	bytes = buf_pos = 0;
	buf_len = 1;
	buf_lenptr = &buf_len;
	buf_posptr = &buf_pos;
	va_start(print, format);
	bytes = print_arg(format, print, buffer,
			      buf_lenptr, buf_posptr, func_print);
	buffer_write(buffer, buf_lenptr, buf_posptr);
	va_end(print);
	return (bytes);
}
