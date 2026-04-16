#include <unistd.h>
#include <stdlib.h>
int snakelen(char *str)
{
	int i = 0;
	int len = 0;
	while(str[i] != '\0')
	{
		if( str[i] >= 'A' && str[i] <= 'Z' && i != 0)
			len ++;
		len++;
		i++;
	}
	return len;
}
char *came(char *str , int len)
{
	char *snake;
	int i = 0;
	int j = 0;
	
	snake = (char *)malloc(sizeof(char *) * (len + 1));
	while (j <= len)
	{
		if( str[i] >= 'A' && str[i] <= 'Z' && i != 0)
		{
			if (i != 0)
				snake[j++] = '_';
			snake[j] = str[i] + 32;
		}else {
		snake[j] = str[i];
		}
		i++;
		j++;
	}
	snake[len] = '\0';
	return (snake);

}
int main (int c , char **v )
{
	int len = snakelen(v[1]);
	//printf("%s" , came(v[1] , len));
	write(1 , came(v[1] , len) , len);
}
