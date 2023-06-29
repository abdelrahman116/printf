#include "main.h" 
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
                    fputs(str, stdout);
                    count += strlen(str);
                    break;
                }

                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    count += snprintf(NULL, 0, "%d", num);
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

