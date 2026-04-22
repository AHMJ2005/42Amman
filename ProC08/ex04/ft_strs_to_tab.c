/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:34:03 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/22 16:34:23 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	char	*it;
	int		ret;

	it = str;
	ret = 0;
	while (*it != '\0')
	{
		ret++;
		it++;
	}
	return (ret);
}

char	*ft_strdup(char *src)
{
	char	*ret;
	int		len;
	int		ctr;

	len = ft_strlen(src);
	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	ctr = 0;
	while (*src)
		ret[ctr++] = *src++;
	ret[ctr] = 0;
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			ctr;
	t_stock_str	*struct_array;

	struct_array = malloc((ac + 1) * sizeof(t_stock_str));
	if (struct_array == NULL)
		return (NULL);
	ctr = 0;
	while (ctr < ac)
	{
		struct_array[ctr].size = ft_strlen(av[ctr]);
		struct_array[ctr].str = av[ctr];
		struct_array[ctr].copy = ft_strdup(struct_array[ctr].str);
		if (struct_array[ctr].copy == NULL)
			return (NULL);
		ctr++;
	}
	struct_array[ctr].str = 0;
	return (struct_array);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	ctr;

	t_stock_str *arr = ft_strs_to_tab(argc - 1, argv + 1);
	ctr = 0;
	while (ctr < argc - 1)
	{
		printf("%d", arr[ctr].size);
		printf("%s", " ");
		printf("%s", arr[ctr].copy);
		printf("%s", " ");
		printf("%s", arr[ctr].str);
		printf("%s", "\n");
		ctr++;
	}
	return (0);
}
*/
