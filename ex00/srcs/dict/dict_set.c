/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:11:49 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/17 18:12:19 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "dict.h"
#include "ft.h"

void	dict_set(t_dict *dict, char *key, char *value)
{
	ft_strcpy(dict->keys[dict->size], key);
	ft_strcpy(dict->values[dict->size], value);
	dict->size += 1;
}
