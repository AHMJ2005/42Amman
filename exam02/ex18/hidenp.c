#include <unistd.h>
int main(int c , char **v)
{
	int i = 0;
	int j = 0;
	while (v[2] [j] != '\0')
	{
		if(v[1][i] == v[2][j])
			i++;
		if (v[1][i] == '\0')
		{
			write(1 , "1" , 1);
			write(1 , "\n" , 1);
			return 0;
		}
			j++;
	}
	write(1 , "0" , 1);
}
