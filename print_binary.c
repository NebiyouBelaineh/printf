#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* bin_convert - Converts an unsigned int to binary
*
* @num: Number to be converted
*
* Return: Pointer to char
**/

char *bin_convert(unsigned int num)
{
	char *binum, b_num[1024];
	int i, j;

	i = 0;
	while (num != 0)
	{
		b_num[i] = (num % 2) + '0';
		num /= 2;
		i++;
	}
	b_num[i] = '\0';

	binum = malloc(sizeof(char) * (i + 1));
	if (binum == NULL)
		return (NULL);

	i--;
	j = 0;
	while (i >= 0)
	{
		binum[j] = b_num[i];
		j++, i--;
	}
	binum[j] = '\0';
	return (binum);
}

/**
 * bi_print - prints the binary conversion of decimals
 *
 * @args: number to be printed
 * @buffer: Memory for printing
 * @buf_lenptr: buffer length
 * @buf_posptr: Position of a buffer
 *
 * Return: numbers of bytes written to buffer
 **/

int bi_print(va_list args, char buffer[], int *buf_lenptr, int *buf_posptr)
{
	int bytes, i;
	unsigned int n;
	char *bi;

	n = va_arg(args, unsigned int);
	bi = bin_convert(n);
	if (bi == NULL)
		return (0);
	i = bytes = 0;
	while (bi[i] != '\0')
	{
		buffer[*buf_posptr] = bi[i];
		*buf_posptr += 1;
		*buf_lenptr += 1;
		if (*buf_lenptr == 1024)
		{
			buffer_write(buffer, buf_lenptr, buf_posptr);
		}
		i++, bytes++;
	}
	free(bi);
	return (bytes);
}
