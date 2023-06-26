#include "main.h"
int _printf(const char * const format, ...)
{
	int i, n = strlen(format);

	va_list printt;

	va_start(printt, format);
	for (i = 0; i < n; i++)
	{
		    if (((format[i] == '%') & (format[i + 1] == 'c')))
			{
				unsigned char x = (unsigned char) va_arg(printt, int);

						write(1,&x,sizeof(char));
					i++;
			}
            else if (((format[i] == '%') & (format[i + 1] == 's')))
			{
				char *x = va_arg(printt, char *);

                    while(*x != '\0')
                    {
                        write(1 , x , 1);
                        x++;
                    }
                    i++;
			}
			else if (((format[i] == '%') & (format[i + 1] == '%')))
			{
					write(1 , &format[i], sizeof(char));
                    i++;
			}
			else
			{
				write(1 , &format[i] , 1);
			}
	}
	return (0);
}
