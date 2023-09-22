#include "main.h"
/**
* support_special_print_015 - supports print_special for special chars from
* 0 to  15
*
* @buffer: buffer to write to
* @buf_lenptr: pointer to current buffer length
* @buf_posptr: pointer to current buffer position
* @str: pointer to the string argument
* @index: index for str position
* @value: value of str at index
*
* Return: void.
*/

void support_special_print_015(char buffer[], int *buf_lenptr, int *buf_posptr,
char *str, int index, int value)
{
	buffer[*buf_posptr] = '0';
	*buf_posptr += 1;
	*buf_lenptr += 1;
	if (*buf_lenptr == 1024)
		buffer_write(buffer, buf_lenptr, buf_posptr);
	if (value > 0 && value <= 9)
		buffer[*buf_posptr] = str[index] + '0';
	else if (value > 9 && value <= 15)
		buffer[*buf_posptr] = str[index] + 55;
	*buf_posptr += 1;
	*buf_lenptr += 1;
	if (*buf_lenptr == 1024)
		buffer_write(buffer, buf_lenptr, buf_posptr);
}

/**
* support_special_print_16_32_127 - supports print_special for special
* chars from 16 to  127
*
* @buffer: buffer to write to
* @buf_lenptr: pointer to current buffer length
* @buf_posptr: pointer to current buffer position
* @index: index for str position
* @value: value of str at index
*
* Return: int
*/

int support_special_print_16_32_127(char buffer[], int *buf_lenptr,
int *buf_posptr, int index, int value)
{
	char *toHex;

	toHex = convert_tohex('X', value);

	if (toHex == NULL)
		return (0);
	index = 0;
	while (toHex[index] != '\0')
	{
		buffer[*buf_posptr] = toHex[index];
		*buf_posptr += 1;
		*buf_lenptr += 1;
		if (*buf_lenptr == 1024)
			buffer_write(buffer, buf_lenptr, buf_posptr);
		index++;
		}
		free(toHex);
	return (0);
}

/**
* handle_nullCase - handles Null case for print_special
*
* @buffer: buffer to write to
* @buf_lenptr: pointer to current buffer length
* @buf_posptr: pointer to current buffer position
* @str: from va_arg
*
* Return: written number of bytes to buffer
*/
int handle_nullCase(char buffer[], int *buf_lenptr, int *buf_posptr,
char *str)
{
	buffer[*buf_posptr] = '\\';
	buf_posptr += 1;
	buf_lenptr += 1;
	if (*buf_lenptr == 1024)
		buffer_write(buffer, buf_lenptr, buf_posptr);
	buffer[*buf_posptr] = 'x';
	buf_posptr += 1;
	buf_lenptr += 1;
	if (*buf_lenptr == 1024)
		buffer_write(buffer, buf_lenptr, buf_posptr);
	buffer[*buf_posptr] = '0';
	buf_posptr += 1;
	buf_lenptr += 1;
	if (*buf_lenptr == 1024)
		buffer_write(buffer, buf_lenptr, buf_posptr);
	buffer[*buf_posptr] = '0';
	buf_posptr += 1;
	buf_lenptr += 1;
	if (*buf_lenptr == 1024)
		buffer_write(buffer, buf_lenptr, buf_posptr);
	return (4);
}
/**
* print_Special - writes printable chars either in chars or
* hex their value in uppercase
*
* @print: string to be printed
* @buffer: buffer to write to
* @buf_lenptr: pointer to current buffer length
* @buf_posptr: pointer to current buffer position
*
* Return: numbers of chars written to buffer
**/
int print_Special(va_list print, char buffer[], int *buf_lenptr,

	int *buf_posptr)
{
	int bytes = 0, i = 0, j;
	char *str;

	str = va_arg(print, char *);
	if (str == NULL)
		return (handle_nullCase(buffer, buf_lenptr, buf_posptr, str));
	while (str[i] != '\0')
	{
		j = str[i];
		if ((j > 0 && j < 32) || j >= 127)
		{
			buffer[*buf_posptr] = '\\';
			*buf_posptr += 1;
			*buf_lenptr += 1;
			if (*buf_lenptr == 1024)
				buffer_write(buffer, buf_lenptr, buf_posptr);
			buffer[*buf_posptr] = 'x';
			*buf_posptr += 1;
			*buf_lenptr += 1;
			if (*buf_lenptr == 1024)
				buffer_write(buffer, buf_lenptr, buf_posptr);
			if (j > 0 && j <= 15)
				support_special_print_015(buffer, buf_lenptr, buf_posptr, str, i, j);
			else if ((j > 16 && j < 32) || j >= 127)
				support_special_print_16_32_127(buffer, buf_lenptr, buf_posptr, i, j);
			bytes += 4;
		}
		else
		{
			buffer[*buf_posptr] = str[i];
			*buf_posptr += 1;
			*buf_lenptr += 1;
			if (*buf_lenptr == 1024)
				buffer_write(buffer, buf_lenptr, buf_posptr);
			bytes++;
		}
		i++;
	}
	return (bytes);
}
