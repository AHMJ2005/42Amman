#include <unistd.h>
int atoi(char *str)
{
	int i = 0;
	int s = 1;
	int res = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s*=-1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return res *s;

}
int is_prime(int n)
{
	int i = 2;
	int j;
	int sum = 0;
	int is_prim ;
	while (i <= n)
	{
		is_prim = 1;
		j = 2;
		while (j < i)
		{
			if (i % j == 0)
			{
				is_prim = 0;
			//	printf("%d i = " , i);
				break;
			}
			j++;
		}
		if (is_prim == 1)
		{
		//	printf("%d" , i);
			sum += i;
		}
		i++;
	}
	return sum;
}
int main(int c , char **v)
{
	int nbr = atoi(v[1]);
	printf("%d atoi \n" , nbr);
	int i = 0;
	int sum = is_prime(nbr);
	printf("%d\n" , sum);

}
