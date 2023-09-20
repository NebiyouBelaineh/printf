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
	if (*buf_lenptr < 1024 - 1)
	{
		buffer[*buf_posptr] = va_arg(print, int);
		*buf_posptr += 1;
		*buf_lenptr += 1;
		buffer[*buf_posptr] = '\0';
		return (1);

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
 * _print_int - Call the function to copy a number to the buffer
 *
 * @print: Va_list of all given arguments to _printf
 * @buffer: The buffer being copied to to print
 * @buf_lenptr: pointer to the current length of the buffer
 * @buf_posptr: pointer to the current position of the buffer
 *
 * Return: number of bytes written to the buffer
 */

int _print_int(va_list print, char buffer[], int *buf_lenptr, int *buf_posptr)
{
	int bytes;
	int num;

	num = va_arg(print, int);
	bytes = print_num(num, buffer, buf_lenptr, buf_posptr);
	return (bytes);
}

/**
 * print_num - copy num to the buffer
 *
 * @num: The integer to print
 * @buffer: buffer to copy to
 * @buf_lenptr: pointer to the current length of the buffer
 * @buf_posptr: pointer to the current position of the buffer
 *
 * Return: Number of characters printed
 */

int print_num(int num, char buffer[], int *buf_lenptr, int *buf_posptr)
{
	int bytes;
	int flag;

	bytes = flag = 0;
	if (*buf_lenptr < 1024 - 1)
	{
	if (num == 0)
	{
		buffer[*buf_posptr] = '0';
		*buf_posptr += 1;
		*buf_lenptr += 1;
		buffer[*buf_posptr] = '\0';
		return (1);
	} else if (*buf_lenptr == 1024)
		buffer_write(buffer, buf_lenptr, buf_posptr);
		return (1);
	}
	else if (num > 0)
		num *= -1;
	else
	{
		buffer[*buf_posptr] = '-';
		*buf_posptr += 1;
		*buf_lenptr += 1;
		if (*buf_lenptr == 1024)
			buffer_write(buffer, buf_lenptr, buf_posptr);
		flag = 1;
	}
	if ((num / 10) != 0)
	{
		bytes = print_num(((num / 10) * -1), buffer, buf_lenptr, buf_posptr);
	}
	buffer[*buf_posptr] = (num % 10) * -1 + '0';
	*buf_posptr += 1;
	*buf_lenptr += 1;
	if (*buf_lenptr == 1024)
		buffer_write(buffer, buf_lenptr, buf_posptr);
	if (flag > 0)
		bytes += flag;
	bytes++;
	return (bytes);
}
