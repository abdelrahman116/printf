#include "main.h"
int _printf(const char * const format, ...)
{	
	long unsigned int j;

	int i, n = strlen(format);

	va_list printt;

	va_start(printt, format);
	for (i = 0; i < n; i++)
	{
		    if (((format[i] == '%') & (format[i + 1] == 'c')))
			{
				unsigned char x = (unsigned char) va_arg(printt, int);

						_putchar(x);
					i++;
			}
            else if (((format[i] == '%') & (format[i + 1] == 's')))
			{
				char *x = va_arg(printt, char *);
                for (j = 0 ;j < (strlen(x)*100) ;j++)
                {
                       _putchar(*x++);
                }
             
                i++;
			}
			else if (((format[i] == '%') & (format[i + 1] == '%')))
			{
					_putchar(format[i]);
                    i++;
			}
			else
			{
				_putchar(format[i]);
			}
	}
	return (0);
}
