#include <unistd.h>
void putchar(char c)
{
	write(1 , &c ,1 );
}
int atoi_base(char *str)
{
	int i = 0;
	int s = 1;
	int res = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return res * s;
}
void to_hex(int n)
{
	char *hex ="0123456789abcdef";
	if(n >= 16)
		to_hex(n / 16);
	write(1,&hex[n % 16], 1);
}
int main(int c , char **v)
{
	int nbr = atoi_base(v[1]);
	to_hex(nbr);

}
