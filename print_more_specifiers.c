#include "main.h"

/**
* print_reverse - writes the reverse of the argument string to buffer
*
* @print: string to be printed from arguments
* @buffer: buffer to write to
* @buf_lenptr: pointer to the current length of the buffer
* @buf_posptr: pointer to the current position of the buffer
*
* Return: numbers of chars written to buffer
**/

int print_reverse(va_list print, char buffer[], int *buf_lenptr,
int *buf_posptr)
{
	char *str;
	int i = 0, bytes = 0;

	str = va_arg(print, char *);
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
		i++;
	i--;
	for (; i >= 0; i--, bytes++)
	{
		buffer[*buf_posptr] = str[i];
		*buf_posptr += 1;
		*buf_lenptr += 1;
		if (*buf_lenptr == 1024)
			buffer_write(buffer, buf_lenptr, buf_posptr);
	}
	return (bytes);
}

/**
* print_rot13 - writes the rot13'ed string to buffer
*
* @print: string to be printed
* @buffer: buffer to write to
* @buf_lenptr: pointer to current buffer length
* @buf_posptr: pointer to current buffer position
*
* Return: numbers of chars written to buffer
**/

int print_rot13(va_list print, char buffer[], int *buf_lenptr, int *buf_posptr)
{
	int i = 0, bytes = 0;
	char *str, tmp;

	str = va_arg(print, char *);
	if (str == NULL)
		str = "(nil)";
	while (str[i] != '\0')
	{
		tmp = str[i];
		if ((tmp >= 'A' && tmp <= 'M') ||
		    (tmp >= 'a' && tmp <= 'm'))
			tmp += 13;
		else if ((tmp >= 'N' && tmp <= 'Z')
			 || (tmp >= 'n' && tmp <= 'z'))
			tmp -= 13;

		buffer[*buf_posptr] = tmp;
		*buf_posptr += 1;
		*buf_lenptr += 1;
		if (*buf_lenptr == 1024)
			buffer_write(buffer, buf_lenptr, buf_posptr);
		i++, bytes++;
	}
	return (bytes);
}

/**
* print_pointer - writes the address of a variable to buffer
*
* @print: string to be printed
* @buffer: buffer to write to
* @buf_lenptr: pointer to current buffer length
* @buf_posptr: pointer to current buffer position
*
* Return: numbers of chars written to buffer
**/

int print_pointer(va_list print, char buffer[], int *buf_lenptr,
	int *buf_posptr)
{
	char *ptr;
	int i = 0, bytes = 0;
	size_t address;

	address = (size_t)va_arg(print, void *);
	ptr = size_tHex('x', address);
	if (ptr == NULL)
		return (0);
	i = bytes = 0;
	buffer[*buf_posptr] = '0';
	bytes++;
	*buf_posptr += 1;
	*buf_lenptr += 1;
	if (*buf_lenptr == 1024)
		buffer_write(buffer, buf_lenptr, buf_posptr);
	buffer[*buf_posptr] = 'x';
	bytes++;
	*buf_posptr += 1;
	*buf_lenptr += 1;
	if (*buf_lenptr == 1024)
	buffer_write(buffer, buf_lenptr, buf_posptr);
	while (ptr[i] != '\0')
	{
		buffer[*buf_posptr] = ptr[i];
		*buf_posptr += 1;
		*buf_lenptr += 1;
		if (*buf_lenptr == 1024)
			buffer_write(buffer, buf_lenptr, buf_posptr);
		i++, bytes++;
	}
	free(ptr);
	return (bytes);
}
