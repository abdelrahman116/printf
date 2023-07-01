#include "main.h"

void print_binary(unsigned int num)
{
	if (num > 1)
		print_binary(num / 2);

	putchar('0' + (num % 2));
}

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;

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

					const char *str = va_arg(args, const char *);
					count += fputs(str, stdout);
					break;
				}

				case 'd':
				case 'i':
				{
					int num = va_arg(args, int);
					count += printf("%d", num);
					break;
				}

				case 'b':
				{
					unsigned int num = va_arg(args, unsigned int);
					print_binary(num);
					count += sizeof(num) * 8;
					break;
					}

				case '%':
				{
					putchar('%');
					count++;
					break;
				}

			}
		}
		else
		{
			putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);

	return count;
}

