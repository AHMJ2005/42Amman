#include <unistd.h>
int main (int c , char **v)
{
	int i = 0;
	if (c == 4)
	{
		while (v[1][i] != 0)
		{
			if (v[1][i] == *v[2])
				v[1][i] = *v[3];
			write (1 , &v[1][i] , 1);
			i++;
		}

	}else
		write (1 , "\n" ,1);
}
