#include <unistd.h>

int main(int c , char **v)
{
	char cc;
	if (c == 2)
	{
		int i = 0;
		while (v[1][i] != 0)
		{
			if (v[1][i] >= 'a' && v[1][i] <= 'z')
			{
				if (v[1][i] > 'a' + 13)
				{
					cc = v[1][i] - 13;
					write (1 , &cc ,1);
				}else 
				{
					cc = v[1][i] + 13;
					write(1 , &cc ,1);
				}
			}
			else if( v[1][i] >= 'A' && v[1][i] <= 'Z')
			{
                                if (v[1][i] > 'A' + 13)
                                {
                                        cc = v[1][i] - 13;
                                        write (1 , &cc ,1);
                                }else
                                {
                                        cc = v[1][i] + 13;
                                        write(1 , &cc ,1);
                                }
			}else
				write(1 , &v[1][i] , 1);
			i++;
		}

	}else 
		write(1 , "\n" , 1);
}
