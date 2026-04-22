/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:37:45 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/22 14:44:31 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

int		ft_strlen(char *str);
char	*ft_strdup(char *str);

int	get_map_len(char **map)
{
	int	ret;

	ret = 0;
	if (map == NULL)
		return (0);
	while (map[ret] != NULL)
	{
		ret++;
	}
	return (ret);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i] != NULL)
	{
		write(1, map[i], ft_strlen(map[i]));
		write(1, "\n", 1);
		i++;
	}
}

void	delete_map(char **map)
{
	int	rows;
	int	ctr;

	rows = get_map_len(map);
	ctr = 0;
	while (ctr < rows)
	{
		if (map[ctr] == NULL)
		{
			ctr++;
			continue ;
		}
		free(map[ctr++]);
	}
	free(map);
}

char	**copy_map(char **map)
{
	int		rows;
	int		ctr;
	char	**ret;

	rows = get_map_len(map);
	ret = malloc((rows + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	ctr = 0;
	while (ctr < rows)
	{
		ret[ctr] = ft_strdup(map[ctr]);
		if (ret[ctr] == NULL)
		{
			delete_map(ret);
			return (NULL);
		}
		ctr++;
	}
	ret[ctr] = NULL;
	return (ret);
}
