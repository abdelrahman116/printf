#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"
void print_binary(unsigned int num)
{
	if (num > 1)
		print_binary(num / 2);

	putchar('0' + (num % 2));
}

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++; /* Move past the '%' */

			/* Handle the conversion specifiers */
			switch (*format)
			{
				case 'c':
				{
					/* Fetch the next argument of type 'int' and print it as a character */
					int ch = va_arg(args, int);
					putchar(ch);
					count++;
					break;
				}

				case 's':
				{
					/* Fetch the next argument of type 'char*' and print it as a string */
					const char *str = va_arg(args, const char *);
					count += fputs(str, stdout);
					break;
				}

				case 'd':
				case 'i':
				{
					/* Fetch the next argument of type 'int' and print it as a decimal integer */
					int num = va_arg(args, int);
					count += printf("%d", num);
					break;
				}

				case 'b':
				{
					/* Fetch the next argument of type 'unsigned int' and print it as binary */
					unsigned int num = va_arg(args, unsigned int);
					print_binary(num);
					count += sizeof(num) * 8; /* Assuming 32-bit unsigned int */
					break;
					}

				case '%':
				{
					/* Print a literal '%' character */
					putchar('%');
					count++;
					break;
				}

				default:
					/* Unsupported conversion specifier, ignore it */
					break;
			}
		}
		else
		{
			/* Regular character, print it */
			putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);

	return count;
}
