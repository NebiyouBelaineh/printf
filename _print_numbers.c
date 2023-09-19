#include "main.h"
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
	if (num == 0)
	{
		buffer[*buf_posptr] = '0';
		*buf_posptr += 1;
		*buf_lenptr += 1;
		if (*buf_lenptr == 1024)
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
