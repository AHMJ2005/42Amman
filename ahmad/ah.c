#include <stdio.h>
#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	ft_putchar(n + '0')
}

void	outputShap(int **shap)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(shap[i][j]);
			if (j < 3)
				ft_putnbr(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	*ft_bzero(void *ptr ,int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}
int main()
{
	int	**shap;
	int	i;
	int	*input;

	input = (int *)malloc(sizeof(int) *4);
	shap = (int **)malloc(sizeof(int *) * 4);
	if(!shap)
		return ;
	i = 0;
	while (i < 4)
	{
		shap[i] = (int *)malloc(sizeof(int) * 4);
		if (!shap)
			return;
		i++;
	}
	if (argc != 2 || !if_input_not_valid/*shoud be bulid*/)
	{
		write(1 , "Error\n", 6);
		return (1);
	}
	ft_bzero(shap , sizeof(int) * 4 * 4);
	if (!Sol)
		write(1 ,"Error\n", 6);
	else
		print
}

