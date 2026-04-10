/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:39:36 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/10 18:47:18 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int     prase_input(char *arg, int *input);
int     solve(int row, int col, int **shap, int *input);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	ft_putchar(n + '0');
}

void	ft_outputshap(int **shap)
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

void	*ft_bzero(void *ptr, int n)
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

int	main(int argc, char **argv)
{
	int	**shap;
	int	i;
	int	*input;

	input = (int *)malloc(sizeof(int) * 16);
	shap = (int **)malloc(sizeof(int *) * 16);
	if (!(shap))
		return (1);
	i = 0;
	while (i < 4)
	{
		shap[i] = (int *)malloc(sizeof(int) * 4);
		if (!shap)
			return (1);
		i++;
	}
	if (argc != 2 || !prase_input(argv[1], input))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	ft_bzero(shap, sizeof(int) * 4 * 4);
	if (!solve(0, 0, shap, input))
		write(1, "Error\n", 6);
	else
		ft_outputshap(shap);

	free(shap);
	free(input);
}
