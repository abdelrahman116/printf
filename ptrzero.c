#include "main.h"
int _printf(const char * const format, ...)
{
	unsigned int i = 0;

	va_list printt;

	va_start(printt, format);
  
   for ( i = 0 ; i < strlen(format) ; i++)
    {
      if (format[i] == '%')
            {
                switch (format[i+1])
                {
                case 'c':
                  {char x = va_arg(printt, int);
                    _putchar(x);
                        i++;
                    break;}
                case 's':
                  {char *x = va_arg(printt, char *);
                    while(*x)
						{_putchar(*x++);}
                        i++;
                    break;}
                case '%':
                  {
                        _putchar('%');
                        i++;
                    break;}        
                }
            } 
        else 
        {
            _putchar(format[i]);
        }
        }
    va_end (printt);
    return (0);
}
