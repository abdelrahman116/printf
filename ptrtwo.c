#include "main.h"
void print_binary(unsigned int num)
{
	if (num > 1)
		print_binary(num / 2);

	putchar('0' + (num % 2));
}
