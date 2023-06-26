#include "main.h"
int _printf(const char * const format, ...)
{
	int i, n = strlen(format);

	va_list printt;

	va_start(printt, format);
	for (i = 0; i < n; i++)
	{
		if (((format[i] == '%') & (format[i + 1] == 'd')))
			{
					int x = va_arg(printt, int);

						printf("%d",x);
					i++;
			}
			else if (((format[i] == '%') & (format[i + 1] == 's' )))
			{
				char *x = va_arg(printt, char *);

					printf("%s", x);
					i++;
			}
			else if (((format[i] == '%') & (format[i + 1] == 'f' )))
			{
				double x = va_arg(printt, double);

					printf("%f", x);
					i++;
			}
			else if (((format[i] == '%') & (format[i + 1] == 'c')))
			{
				unsigned char x = (unsigned char) va_arg(printt, int);

					printf("%c", x);
					i++;
			}
			else if (((format[i] == '%') & (format[i + 1] == '%' )))
			{
					printf("%");
			}
			else
			{
				printf("%c", format[i]);
			}
	}
	return (0);
}
