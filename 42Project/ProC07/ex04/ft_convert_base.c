/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:24:03 by aalbess           #+#    #+#             */
/*   Updated: 2025/09/28 10:26:01 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_convert(int nbr, char *base_to);
char	*rev(char *res);
int		is_space(char c);

int	base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	check_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	valid(char *base)
{
	int	i;
	int	j;

	if (base_len(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	sign;
	int	len;
	int	index;
	int	res;

	while (is_space(*nbr))
		nbr++;
	sign = 1;
	res = 0;
	len = base_len(base);
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	while (*nbr)
	{
		index = check_index(*nbr, base);
		if (index == -1)
			break ;
		res = (res * len) + index;
		nbr++;
	}
	return (res * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*p;
	int		n;

	if (!valid(base_from) || !valid(base_to))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	p = ft_convert(n, base_to);
	return (p);
}
