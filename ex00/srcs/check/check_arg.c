/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:52:42 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/17 17:53:19 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "check.h"

int	check_arg(int argc, char **argv, char *default_dict)
{
	if (argc < 2 || argc > 3)
		return (0);
	if (argc == 2)
	{
		if (!(check_digits(argv[1])))
			return (0);
		if (!(check_dict_file(default_dict)))
		{
			return (-1);
		}
	}
	if (argc == 3)
	{
		if (!check_dict_file(argv[1]))
		{
			return (-1);
		}
		if (!check_digits(argv[2]))
			return (0);
	}
	return (1);
}
