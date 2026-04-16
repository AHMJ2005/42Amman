#include <unistd.h>
#include <stdio.h>
int main(int argc , char **argv)
{
	int i = 0;
//	char *a = argv[1];
	if(argc == 2)
	{
		        while (argv[1][i] != '\0' )
                i++;
        int size = i;
		while(size >=0)
		{
			write(1 , &argv[1][size] , 1);
			size--;
		}

	}else 
		write(1 , "\n" , 1);
}
