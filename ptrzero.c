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
                    count += puts(str);
                    break;
                }

                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    char numStr[12];
                    sprintf(numStr, "%d", num);
                    count += puts(numStr);
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

