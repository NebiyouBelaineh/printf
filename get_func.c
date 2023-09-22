#include "main.h"

/**
* get_func - gets the right function and calls a respective function
* to print arguments depending on conversion specifier
*
* @format: pointer to the format to be checked
* @track: tracks index of format
* @func_print: Struct holding appropriate function for conversion
* @buffer: Buffer needed to copy
* @buf_lenptr: Pointer to the length of the buffer
* @buf_posptr: Pointer to the position within the buffer
* @print: va_list to retrieve all arguments to _printf function
*
* Return: Return the number of bytes copied
*
*/

int get_func(const char *format, int *track, prt_func func_print[],
char buffer[], int *buf_lenptr, int *buf_posptr, va_list print)
{
	int i, bytes = 0, len = 13, index;

	index = *track;

	for (i = 0; i < len; i++)
	{
		if (format[index] == func_print[i].symbol)
		{
			bytes += func_print[i].fun_pt(print, buffer, buf_lenptr, buf_posptr);
			return (bytes);
		}
	}
	if (format[index] != '\0')
	{
		bytes += buffer_copy(format[index - 1], buffer, buf_lenptr,
		buf_posptr);
		bytes += buffer_copy(format[index], buffer, buf_lenptr,
		buf_posptr);
	}
	return (bytes);
}
