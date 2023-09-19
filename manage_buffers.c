#include "main.h"

/**
 * init_buffer - Initializes buffer with null for writing to stdout
 *
 * @buffer: The buffer that needs to be initialized
 *
 * Return: void
 */

void init_buffer(char buffer[])
{
	int i = 0;

	while (i < 1024)
	{
		buffer[i] = 0;
		i++;
	}
	buffer[i] = '\0';
}



/**
 * buffer_write - Writes buffer to standard out
 *
 * @buffer: The buffer with the string needed to print
 * @buf_len: Pointer to the length of buffer
 * @buf_pos: Pointer to the postion inside buffer
 *
 * Return: Void
 */
void buffer_write(char buffer[], int *buf_len, int *buf_pos)
{
	write(1, buffer, *buf_len - 1);
	*buf_pos = 0;
	*buf_len = 1;
}

/**
* buffer_copy - Copies character to a buffer
*
* @format: Character to be copied
* @buffer: Buffer to hold the copied format
* @buf_lenptr: Pointer to the length of the buffer
* @buf_posptr: Pointer to the position inside the buffer
*
* Return: Number of characters copied
*/

int buffer_copy(char format, char buffer[],
		     int *buf_lenptr, int *buf_posptr)
{
	int bytes;

	bytes = 0;
	buffer[*buf_posptr] = format;
	*buf_posptr += 1;
	*buf_lenptr += 1;
	if (*buf_lenptr == 1024)
	{
		buffer_write(buffer, buf_lenptr, buf_posptr);
	}
	bytes++;
	return (bytes);
}
