/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_int_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:35:24 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/22 13:45:13 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

int	ft_get_line_len(char **map)
{
	int	i;

	i = 0;
	if (!map || !map[0])
		return (0);
	while (map[0][i])
		i++;
	return (i);
}

int	**ft_generate_int_map(char **map)
{
	int	**dp;
	int	rows;
	int	cols;
	int	i;

	rows = get_map_len(map);
	cols = ft_get_line_len(map);
	dp = malloc(sizeof(int *) * rows);
	if (!dp)
		return (0);
	i = 0;
	while (i < rows)
	{
		dp[i] = malloc(sizeof(int) * cols);
		if (!dp[i])
			return (NULL);
		i++;
	}
	return (dp);
}
