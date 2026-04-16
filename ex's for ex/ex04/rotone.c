#include <unistd.h>

int main(int c , char **v)
{
	int i =0;
	char cc;
	while (v[1][i] != 0)
	{
		if ( v[1][i] >= 'a' && v[1][i] <'z')
		{
			char cc = v[1][i] + 1;
		      write(1 , &cc,1);
		     // i++;
		}else if ( v[1][i] >= 'A' && v[1][i] < 'Z')
		{
                       cc = v[1][i] + 1;
                      write(1 , &cc,1);
                      //i++;
		}else if (v[1][i] == 'z')
		{
			write(1 , "a" , 1);

		}else if(v[1][i] == 'Z')
			write(1 ,"A" , 1);
		else 
			write(1 , &v[1][i],1);
		i++;
	}
}
