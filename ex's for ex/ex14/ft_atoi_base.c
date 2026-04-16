int ft_atoi_base(const char *str, int base)
{
	char *number;
	int res = 0;
	int s = 1;
	int i = 0;

	number = (char *)str;
	if (number[i] == '-')
	{
		s *= -1;
		i++;
	}
	while (number[i] != 0)
	{
		if (number[i] >= '0' && number[i] <= '9')
			res = res * base + number[i] - 48;
		else if (number[i] >= 'A' && number[i] <= 'F')
			res = res * base + number[i] - '7';
		else if (number[i] >= 'a' && number[i] <= 'f')
			res = res * base + number[i] - 'W';
		i++;
	}
	return res * s;
}

#include <stdio.h>
int main()
{
	printf("%d\n" , ft_atoi_base("-101" , 2) );
}
