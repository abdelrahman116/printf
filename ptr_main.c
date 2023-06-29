#include "main.h"
/**
 * _printf - Custom printf function that supports various conversion specifiers.
 * @format: The format string containing the conversion specifiers.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	int count = 0;
    va_list args;
	va_start(args, format);

    while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
				{
					int ch = va_arg(args, int);
					putchar(ch);
					count++;
					break;
				}

				case 's':
				{
					const char *str = va_arg(args, const char*);
					count += fputs(str, stdout);
					break;
				}

				case 'd':
				case 'i':
				{
					int num = va_arg(args, int);
					count += print_decimal(num);
					break;
				}

				case 'u':
				{
					unsigned int num = va_arg(args, unsigned int);
					count += print_unsigned_decimal(num);
					break;
				}

				case 'o':
				{
					unsigned int num = va_arg(args, unsigned int);
					count += print_octal(num);
					break;
				}

				case 'x':
				{
					unsigned int num = va_arg(args, unsigned int);
					count += print_hexadecimal(num, 0);
					break;
				}

				default:
					break;
			}
		}
		else
			putchar(*format);

		count++;
		format++;
	}

	va_end(args);

	return count;
}
