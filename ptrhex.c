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
	return sprintf(buffer + *count, "%d", num);
}

/**
 * print_unsigned_decimal - Prints an unsigned decimal integer.
 * @num: The unsigned decimal integer to be printed.
 * @buffer: The buffer to store the unsigned decimal integer.
 * @count: The pointer to the count of characters printed.
 *
 * Return: The number of characters printed.
 */
int print_unsigned_decimal(unsigned int num, char *buffer, int *count)
{
	return sprintf(buffer + *count, "%u", num);
}

/**
 * print_octal - Prints an octal integer.
 * @num: The octal integer to be printed.
 * @buffer: The buffer to store the octal integer.
 * @count: The pointer to the count of characters printed.
 *
 * Return: The number of characters printed.
 */
int print_octal(unsigned int num, char *buffer, int *count)
{
	return sprintf(buffer + *count, "%o", num);
}

/**
 * print_hexadecimal - Prints a hexadecimal integer.
 * @num: The hexadecimal integer to be printed.
 * @buffer: The buffer to store the hexadecimal integer.
 * @count: The pointer to the count of characters printed.
 * @uppercase: Indicates whether to print uppercase letters.
 *
 * Return: The number of characters printed.
 */
int print_hexadecimal(unsigned int num, char *buffer, int *count, int uppercase)
{
	if (uppercase)
		return sprintf(buffer + *count, "%X", num);
	else
		return sprintf(buffer + *count, "%x", num);
}
