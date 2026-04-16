#include <unistd.h>
void ch(int a)
{
	char c;
	if (a >= 10)
		ch(a / 10);
	 //write (1 , &c , 1);
	 c = a % 10 + '0';
	write (1 , &c , 1);
	//write (1 , "\n" , 1);
}
void fizzbuzz(void)
{
	int i = 1;
	while (i <= 100){
	if (i % 3 == 0 && i % 5 == 0)
		write(1 , "fizzbuzz\n" , 9);
	else if (i % 5 == 0)
		write(1 , "buzz\n" , 5);
	else if (i % 3 == 0)
		write (1 , "fizz\n" , 5);
	else
	{
		ch(i);
		write (1 , "\n" , 1);
	}
	i++;
}
}
int main()
{
	fizzbuzz();
}
