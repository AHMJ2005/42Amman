#include <unistd.h>

void repeat(char *str)
{
	int i = 0;
	int count = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			count = (str[i] - 'a') + 1;
			while (count > 0){
				write(1 ,&str[i] ,1 );
				count--;
			}
			

		} else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			count = (str[i] - 'A') + 1;
                        while (count > 0){
                                write(1 ,&str[i] ,1 );
                                count--;
                        }
		}else 
			write(1 , &str[i] , 1);
		i++;
	}
}
int main(int argc , char **argv)
{
	if (argc == 2)
		repeat(argv[1]);
	else 
		write(1 , "\n" , 1);
}
