/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:08:38 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/17 18:09:55 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "dict.h"
static char	**str_arr_new(void)
{
	char	**arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(char *) * 128);
	while (i < 128)
	{
		arr[i] = malloc(sizeof(char *) * 128);
		i++;
	}
	return (arr);
}

t_dict	dict_new(void)
{
	t_dict	dict;

	dict.keys = str_arr_new();
	dict.values = str_arr_new();
	dict.size = 0;
	return (dict);
}
