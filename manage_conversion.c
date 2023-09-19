#include "main.h"

/**
* convert_tohex - represents decimal number greater than 9 to hex
* @size: char for uppercase or lowercase letter conversion
* @h: number to be converted
* Return: pointer to a char
**/
char *convert_tohex(char size, unsigned int h)
{
	char *hex_num, buff[1024];

	int index1, index2, r;

	index1 = 0;
	while (h != 0)
	{
		r = h % 16;
		if (r > 9)
		{
			if (size == 'X')
				buff[index1] = r + 55;
			else
				buff[index1] = r + 87;
		}
		else
			buff[index1] = r + 48;
		h /= 16;
		index1++;
	}
	buff[index1] = '\0';

	hex_num = malloc(sizeof(char) * index1);
	if (buff == NULL)
		return (NULL);
	index1--;
	for (index2 = 0; index1 >= 0; index2++, index1--)
		hex_num[index2] = buff[index1];
	hex_num[index2] = '\0';
	return (hex_num);
}
/**
* size_tHex - converts to hex decimals above 9
* @size: char for uppercase or lowercase letter conversion
* @n: based on size of a number it gets converetd in hex
* Return: pointer to a char
**/
char *size_tHex(char size, size_t n)
{
	char *hex_num, buff[1024];

	int index1, index2;

	long r;

	index1 = 0;
	while (n != 0)
	{
		r = n % 16;
		if (r > 9)
		{
			if (size == 'X')
				buff[index1] = r + 55;
			else
				buff[index1] = r + 87;
		}
		else
			buff[index1] = r + 48;
		n /= 16;
		index1++;
	}
	buff[index1] = '\0';

	hex_num = malloc(sizeof(char) * index1);
	if (hex_num == NULL)
		return (NULL);
	index1--;
	for (index2 = 0; index1 >= 0; index2++, index1--)
		hex_num[index2] = buff[index1];
	hex_num[index2] = '\0';
	return (hex_num);
}

/**
* convert_toUnsignedInt - represents a signed number into unsigned
* @num: number to be converted
* Return: areturns unsigned int
**/
unsigned int convert_toUnsignedInt(int num)
{
	unsigned int ui;

	ui = UINT_MAX + 1 + num;
	return (ui);
}

/**
* convert_toOctal - represents a decimal number greater than 7 to octal
* @oct: unsigned int number to be converted
* Return: pointer to a char
**/
char *convert_toOctal(unsigned int oct)
{
	int index1, n, r;
	char *octal, buff[1024];

	n = 0;
	while (oct != 0)
	{
		r = (oct % 8) + '0';
		buff[n] = r;
		oct /= 8;
		n++;
	}
	buff[n] = '\0';

	octal = malloc(sizeof(char) * n);
	if (octal == NULL)
		return (NULL);
	n--;
	index1 = 0;
	while (n >= 0)
	{
		octal[index1] = buff[n];
		index1++, n--;
	}
	octal[index1] = '\0';
	return (octal);
}
