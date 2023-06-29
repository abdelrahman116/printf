#include "main.h" 
int _printf(const char *format, ...)
{   
    int count = 0;
    va_list _printt;
    va_start(_printt, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                {
                    int ch = va_arg(_printt, int);
                    putchar(ch);
                    count++;
                    break;
                }

                case 's':
                {
                    const char *str = va_arg(_printt, const char*);
                    fputs(str, stdout);
                    count += strlen(str);
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
    va_end(_printt);
    return (count);
}

