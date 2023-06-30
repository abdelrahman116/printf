
int print_decimal(int num, char *buffer, int *count)
{
	int digits = 0;
	int temp = num;	
	int i = *count + digits - 1;

	if (num < 0)
	{
		buffer[*count] = '-';
		(*count)++;
		num = -num;
	}

	while (temp != 0)
	{
		temp /= 10;
		digits++;
	}

	while (num != 0)
	{
		buffer[i] = '0' + (num % 10);
		num /= 10;
		i--;
	}

	*count += digits;

	return digits;
}
void convert(unsigned int num, unsigned int base, char *buffer, int *count, int uppercase)
{
	int digits = 0;
	unsigned int temp = num;
	int i = *count + digits - 1;

	if (num == 0)
	{
		buffer[*count] = '0';
		(*count)++;
		return;
	}

	while (temp != 0)
	{
		temp /= base;
		digits++;
	}


	while (num != 0)
	{
		int remainder = num % base;
		buffer[i] = (remainder < 10) ? ('0' + remainder) : (uppercase ? 'A' + remainder - 10 : 'a' + remainder - 10);
		num /= base;
		i--;
	}

	*count += digits;
}
void print_binary(unsigned int num, char *buffer, int *count)
{
	if (num > 1)
		print_binary(num / 2, buffer, count);

	buffer[*count] = '0' + (num % 2);
	(*count)++;
}

