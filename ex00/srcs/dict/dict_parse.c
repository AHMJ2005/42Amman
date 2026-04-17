/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:12:32 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/17 18:12:40 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "dict.h"
#include "ft.h"

int	dict_parse(t_dict *origin, char *str)
{
	int	i;
	int	err_check;
	char	*number;
	char	*word;

	i = 0;
	err_check = 0;
	while (str[i])
	{
		number = malloc(sizeof(char) * 64);
		word = malloc(sizeof(char) * 64);
		err_check = dict_getnbr(number, str + i);
		if (!number || !word || err_check == -1)
			return (-1);
		i += err_check;
		i += dict_skip_to_word(str + i);
		i += dict_getword(word, str + i);
		i += dict_skip_to_next_entry(str + i);
		dict_set(origin, number, word);
		free(number);
		free(word);
	}
	return (0);
}
