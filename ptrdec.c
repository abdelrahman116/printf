#include "main.h"
/**
 * print_decimal - Prints a decimal integer.
 * @num: The decimal integer to be printed.
 * @buffer: The buffer to store the decimal integer.
 * @count: The pointer to the count of characters printed.
 *
 * Return: The number of characters printed.
 */
int print_decimal(int num, char *buffer, int *count)
{

	int digits = 0;
	int temp = num;
    int i = *count + digits - 1;
	if (num < 0)
	{
		buffer[*count] = '-';
		(*count)++;
		num = -num;
	}

	while (temp != 0)
	{
		temp /= 10;
		digits++;
	}
    while (num != 0)
	{
		buffer[i] = '0' + (num % 10);
		num /= 10;
		i--;
	}

	*count += digits;

	return digits;
}
