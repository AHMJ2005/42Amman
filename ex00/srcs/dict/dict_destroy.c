/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:57:07 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/17 17:57:41 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "dict.h"

void	dict_destroy(t_dict *dict)
{
	int	i;

	i = 0;
	while (i < dict -> size)
	{
		free(dict->keys[i]);
		free(dict->values[i]);
		i++;
	}
	free(dict);
}
