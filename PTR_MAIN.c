#include "main.h"
/**
 * _printf - Custom printf function that supports various conversion specifiers.
 * @format: The format string containing the conversion specifiers.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;


	int count = 0;
	char buffer[BUFFER_SIZE];
	int buffer_count = 0;
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
					buffer[buffer_count] = ch;
					buffer_count++;
					count++;
					break;
				}

				case 's':
				{
					const char *str = va_arg(args, const char *);
					int len = strlen(str);
					memcpy(buffer + buffer_count, str, len);
					buffer_count += len;
					count += len;
					break;
				}

				case 'd':
				case 'i':
				{
					int num = va_arg(args, int);
					count += print_decimal(num, buffer, &buffer_count);
					break;
				}

								case 'u':
				{
					unsigned int num = va_arg(args, unsigned int);
					convert(num, 10, buffer, &buffer_count, 0);
					break;
				}

				case 'o':
				{
					unsigned int num = va_arg(args, unsigned int);
					convert(num, 8, buffer, &buffer_count, 0);
					break;
				}

				case 'x':
				{
					unsigned int num = va_arg(args, unsigned int);
					convert(num, 16, buffer, &buffer_count, 0);
					break;
				}

				case 'X':
				{
					unsigned int num = va_arg(args, unsigned int);
					convert(num, 16, buffer, &buffer_count, 1);
					break;
				}
				case 'b':
				{
					unsigned int num = va_arg(args, unsigned int);
					print_binary(num, buffer, &buffer_count);
					count += sizeof(num) * 8;
					break;
				}

				case '%':
				{
					buffer[buffer_count] = '%';
					buffer_count++;
					count++;
					break;
				}

				default:
                buffer[buffer_count] = *format;
					buffer_count++;
					count++;
					break;
			}
		}
		else
		{
			buffer[buffer_count] = *format;
			buffer_count++;
			count++;
		}

		if (buffer_count >= BUFFER_SIZE - 1)
		{
			write(1, buffer, buffer_count);
			buffer_count = 0;
		}

		format++;
	}

	if (buffer_count > 0)
		write(1, buffer, buffer_count);

	va_end(args);

	return count;
}
