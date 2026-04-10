/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_views_partial.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:16:07 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/10 18:32:52 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		parse_input(char *arg, int *input);
int		solve(int row, int col, int **shap, int *input);

void	ft_putnbr(int n)
{
	char c;
	c = n + '0';
	write(1, &c, 1);
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
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}


void	free_all(int **shap, int *input)
{
	int i;

	if (shap)
	{
		i = 0;
		while (i < 4)
		{
			if (shap[i])
				free(shap[i]);
			i++;
		}
		free(shap);
	}
	if (input)
		free(input);
}

int	main(int argc, char **argv)
{
	int	**shap;
	int	i;
	int	j;
	int	*input;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	input = (int *)malloc(sizeof(int) * 16);
	shap = (int **)malloc(sizeof(int *) * 4);
	if (!input || !shap)
		return (1);
	i = 0;
	while (i < 4)
	{
		shap[i] = (int *)malloc(sizeof(int) * 4);
		if (!shap[i])
			return (1);
		j = 0;
		while (j < 4)
			shap[i][j++] = 0;
		i++;
	}
	if (!parse_input(argv[1], input))
	{
		write(1, "Error\n", 6);
		free_all(shap, input);
		return (1);
	}
	if (!solve(0, 0, shap, input))
		write(1, "Error\n", 6);
	else
		ft_outputshap(shap);
	free_all(shap, input);
	return (0);
}
