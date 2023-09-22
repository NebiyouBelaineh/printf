#include "main.h"

/**
 * print_unsigned - retrives the number of written unsigned int to buffer
 * @print: unsigned int argument
 * @buffer: buffer unsigned int is written to
 * @buf_lenptr: pointer to the current length of the buffer
 * @buf_posptr: pointer to the current position of the buffer
 *
 * Return: number of bytes written to buffer
 */

int print_unsigned(va_list print, char buffer[], int *buf_lenptr,
	int *buf_posptr)
{
	unsigned int ui;
	int bytes;

	ui = va_arg(print, unsigned int);
	bytes = print_unsignedInt(ui, buffer, buf_lenptr, buf_posptr);
	return (bytes);
}

/**
 * print_unsignedInt - write unsigned integer to the buffer
 *
 * @num: Integer to copy
 * @buffer: buffer to write to
 * @buf_lenptr: Pointer to the current length of buffer
 * @buf_posptr: Pointer to the cuurrent position of the buffer
 *
 * Return: number of bytes written to buffer
 */

int print_unsignedInt(unsigned int num, char buffer[],
	int *buf_lenptr, int *buf_posptr)
{
	int bytes;

	bytes = 0;
	if (num == 0)
	{
		buffer[*buf_posptr] = '0';
		*buf_posptr += 1;
		*buf_lenptr += 1;
		if (*buf_lenptr == 1024)
			buffer_write(buffer, buf_lenptr, buf_posptr);
		return (1);
	}
	if ((num / 10) != 0)
		bytes = print_unsignedInt((num / 10), buffer, buf_lenptr, buf_posptr);
	buffer[*buf_posptr] = (num % 10) + '0';
	*buf_posptr += 1;
	*buf_lenptr += 1;
	if (*buf_lenptr == 1024)
		buffer_write(buffer, buf_lenptr, buf_posptr);
	bytes++;
	return (bytes);
}

/**
* print_octal - prints the octal version of an unsigned int to buffer
* @print: number to be printed ffrom arguments
* @buffer: buffer to write to
* @buf_lenptr: pointer to the current length of the buffer
* @buf_posptr: pointer to the current position of the buffer
* Return: numbers of chars written to buffer
*/

int print_octal(va_list print, char buffer[], int *buf_lenptr, int *buf_posptr)
{
	unsigned int num;
	int bytes = 0, i = 0;
	char *octal, empty;

	empty = '\0';
	num = va_arg(print, unsigned int);
	if (num == 0)
	{
		empty = num + 48;
		buffer_copy(empty, buffer, buf_lenptr, buf_posptr);
		return (1);
	}
	octal = convert_toOctal(num);
	if (octal == NULL)
		return (0);
	while (octal[i] != '\0')
	{
		buffer[*buf_posptr] = octal[i];
		*buf_posptr += 1;
		*buf_lenptr += 1;
		if (*buf_lenptr == 1024)
		{
			buffer_write(buffer, buf_lenptr, buf_posptr);
		}
		i++, bytes++;
	}
	free(octal);
	return (bytes);
}

/**
* print_hex - prints the hexadecimal conversion of a decimal number, lowercase
* @print: number to be printed
* @buffer: space used for printing
* @buf_lenptr: buffer length
* @buf_posptr: current buffer index
* Return: numbers of chars written to buffer
**/

int print_hex(va_list print, char buffer[], int *buf_lenptr, int *buf_posptr)
{
	unsigned int num;
	int bytes = 0, i = 0;
	char *hex, empty;

	num = va_arg(print, unsigned int);
	if (num == 0)
	{
		empty = num + 48;
		buffer_copy(empty, buffer, buf_lenptr, buf_posptr);
		return (1);
	};

	num = va_arg(print, unsigned int);
	hex = size_tHex('x', num);
	if (hex == NULL)
		return (0);
	i = bytes = 0;
	while (hex[i] != '\0')
	{
		buffer[*buf_posptr] = hex[i];
		*buf_posptr += 1;
		*buf_lenptr += 1;
		if (*buf_lenptr == 1024)
		{
			buffer_write(buffer, buf_lenptr, buf_posptr);
		}
		i++, bytes++;
	}
	free(hex);
	return (bytes);
}

/**
* print_HEX - prints the hexadecimal conversion of a decimal number, uppercase
* @print: number to be printed
* @buffer: space used for printing
* @buf_lenptr: buffer length
* @buf_posptr: current buffer index
* Return: numbers of chars written to buffer
**/

int print_HEX(va_list print, char buffer[], int *buf_lenptr, int *buf_posptr)
{
	int bytes, i;
	unsigned int num;
	char *heX, empty;

	num = va_arg(print, unsigned int);
	if (num == 0)
	{
		empty = num + 48;
		buffer_copy(empty, buffer, buf_lenptr, buf_posptr);
		return (1);
	}
	heX = convert_tohex('X', num);
	if (heX == NULL)
		return (0);
	i = bytes = 0;
	while (heX[i] != '\0')
	{
		buffer[*buf_posptr] = heX[i];
		*buf_posptr += 1;
		*buf_lenptr += 1;
		if (*buf_lenptr == 1024)
		{
			buffer_write(buffer, buf_lenptr, buf_posptr);
		}
		i++, bytes++;
	}
	free(heX);
	return (bytes);
}
