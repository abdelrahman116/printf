#include "main.h"

/**
 * print_decimal - Prints a decimal integer.
 * @num: The decimal integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_decimal(int num)
{
	return printf("%d", num);
}

/**
 * print_unsigned_decimal - Prints an unsigned decimal integer.
 * @num: The unsigned decimal integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_unsigned_decimal(unsigned int num)
{
	return printf("%u", num);
}

/**
 * print_octal - Prints an octal integer.
 * @num: The octal integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_octal(unsigned int num)
{
	return printf("%o", num);
}

/**
 * print_hexadecimal - Prints a hexadecimal integer.
 * @num: The hexadecimal integer to be printed.
 * @uppercase: Indicates whether to print uppercase letters.
 *
 * Return: The number of characters printed.
 */
int print_hexadecimal(unsigned int num, int uppercase)
{
	if (uppercase)
		return printf("%X", num);
	else
		return printf("%x", num);
}
