#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @num: The number to be printed in binary.
 * @buffer: The buffer to store the binary representation.
 * @count: The pointer to the count of characters printed.
 */
void print_binary(unsigned int num, char *buffer, int *count)
{
	if (num > 1)
		print_binary(num / 2, buffer, count);

	buffer[*count] = '0' + (num % 2);
	(*count)++;
}
