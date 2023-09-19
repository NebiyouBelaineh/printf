#include "main.h"

/**
* get_func - gets the right function and calls a respective function
* to print arguments depending on conversion specifier
*
* @format: current format to be checked
* @func_print: Struct holding appropriate function for conversion
* @buffer: Buffer needed to copy
* @buf_lenptr: Pointer to the length of the buffer
* @buf_posptr: Pointer to the position within the buffer
* @print: va_list to retrieve all arguments to _printf function
*
* Return: Return the number of bytes copied
*
*/

int get_func(char format, prt_func func_print[], char buffer[],
		int *buf_lenptr, int *buf_posptr, va_list print)
{
	int i, bytes, len = 12;

	bytes = 0;
	for (i = 0; i < len; i++)
	{
		if (format == func_print[i].symbol)
		{
			bytes += func_print[i].fun_pt(print, buffer, buf_lenptr, buf_posptr);
			return (bytes);
		}
	}
	return (0);
}
