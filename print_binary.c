#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* bin_convert - represents an unsigned int to binary
*
* @num: Number to be converted
*
* Return: pointer to char
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

	binum = malloc(sizeof(char) * i);
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
