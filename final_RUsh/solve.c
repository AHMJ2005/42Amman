/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:36:22 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/22 14:14:33 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void	p_cell(char **map, int **dp, t_point *best, char *key)
{
	int	i;
	int	j;

	i = best->curr_y;
	j = best->curr_x;
	if (map[i][j] == key[1])
		dp[i][j] = 0;
	else if (i == 0 || j == 0)
		dp[i][j] = 1;
	else
		dp[i][j] = ft_min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
	if (dp[i][j] > best->size)
	{
		best->size = dp[i][j];
		best->y = i;
		best->x = j;
	}
}

void	ft_free_int_map(int **dp, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}

char	**solve(char **map, char *key)
{
	int		**dp;
	t_point	b;
	int		i;
	int		j;

	b.size = 0;
	dp = ft_generate_int_map(map);
	if (!dp)
		return (NULL);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			b.curr_y = i;
			b.curr_x = j;
			p_cell(map, dp, &b, key);
			j++;
		}
		i++;
	}
	draw_square(map, b, key[2]);
	ft_free_int_map(dp, map);
	return (map);
}

void	draw_square(char **map, t_point b, char full)
{
	int	i;
	int	j;

	i = b.y - b.size + 1;
	while (i <= b.y)
	{
		j = b.x - b.size + 1;
		while (j <= b.x)
		{
			map[i][j] = full;
			j++;
		}
		i++;
	}
}
