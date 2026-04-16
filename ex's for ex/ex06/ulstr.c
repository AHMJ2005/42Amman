#include <unistd.h>

int main(int c , char **v)
{
	int i = 0;
	char cc;
	while (v[1][i] != 0)
	{
		if ( v[1][i] >= 'A' && v[1][i] <= 'Z')
		{
			cc = v[1][i] + 32;
			write(1 , &cc , 1);
		}else if ( v[1][i] >= 'a' && v[1][i] <= 'z')
		{
			cc = v[1][i] -32;
			write(1 , &cc , 1);
		}else 
			write(1 , &v[1][i] ,1);
		i++;
	}
	write(1 , "\n" ,1);
}
