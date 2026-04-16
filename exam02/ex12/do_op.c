#include <unistd.h>
#include <stdio.h>

int atoi(char *str)
{
	int s = 1;
	int i = 0;
	int res = 0;
	while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9'){
		res = res * 10 + str[i] - 48;
		i++;
	}
	return res*s;
}
int main(int c , char **v)
{
	int n1 = atoi(v[1]);
	int n2 = atoi(v[3]);
	if (c == 4){
	if (*v[2] == '+')
	{
		int sum = n1 + n2;
		printf("%d" , sum);
	}else if (*v[2] == '*')
	{
		int multi = n1 * n2;
		printf("%d" , multi);
	}else if (*v[2] == '-')
	{
		int sub = n1 - n2;
		printf("%d" , sub);
	}else if (*v[2] == '/')
	{
		int div = n1 / n2;
		printf("%d" , div);
	}else if (*v[2] == '%')
	{
		int mod = n1 % n2;
		printf("%d" , mod);
	}
	write(1 , "\n" , 1);
	}else
		write(1 , "\n" , 1);
}
