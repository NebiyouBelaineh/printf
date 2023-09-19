#include "main.h"

/**
* print_char - writes character argument to buffer
*
* @print: character to be printed from variadic function
* @buffer: buffer to write to
* @buf_lenptr: pointer to the current length of the buffer
* @buf_posptr: pointer to the current position of the buffer
*
* Return: number of bytes written(1 since pritning char);
*/

int print_char(va_list print, char buffer[], int *buf_lenptr, int *buf_posptr)
{
	if (*buf_lenptr < 1024)
	{
		buffer[*buf_posptr] = va_arg(print, int);
		*buf_posptr += 1;
		*buf_lenptr += 1;
		if (*buf_lenptr == 1024)
			buffer_write(buffer, buf_lenptr, buf_posptr);
	}
	else
	{
		buffer_write(buffer, buf_lenptr, buf_posptr);
		buffer[*buf_posptr] = va_arg(print, int);
		*buf_posptr += 1;
		*buf_lenptr += 1;
	}
	return (1);
}

/**
 * print_string - writes string to buffer
 * @print: Va_list of all given arguments to _printf
 * @buffer: buffer to write string to
 * @buf_lenptr: pointer to the current length of the buffer
 * @buf_posptr: pointer to the current position of the buffer
 *
 * Return: Returns number of characters written to the buffer
 */

int print_string(va_list print, char buffer[], int *buf_lenptr,
	int *buf_posptr)
{
	char *str;
	int i = 0, bytes = 0;

	str = va_arg(print, char *);
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		buffer[*buf_posptr] = str[i];
		*buf_posptr += 1;
		*buf_lenptr += 1;
		if (*buf_lenptr == 1024)
			buffer_write(buffer, buf_lenptr, buf_posptr);
		i++;
		bytes++;
	}
	return (bytes);
}


/**
* print_percent - prints percent character
*
* @print: character to be printed from variadic function
*
* Return: number of byte printed;
*/

int print_percent(va_list print)
{
	int byte = 0;

	if (va_arg(print, int) == '%')
	{
		_putchar(va_arg(print, int));
		byte++;
		return (byte);
	}
	_putchar('%');
	byte++;
	return (byte);
}
