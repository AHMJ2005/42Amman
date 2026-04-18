/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 09:36:55 by aalbess           #+#    #+#             */
/*   Updated: 2025/09/28 12:38:42 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		base_len(char *base);
int		check_index(char c, char *base);
int		valid(char *base);
int		ft_atoi_base(char *nbr, char *base);

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char	*rev(char *res)
{
	char	temp;
	int		i;
	int		size;

	i = 0;
	size = base_len(res);
	while (i < size / 2)
	{
		temp = res[i];
		res[i] = res[size - 1 - i];
		res[size - 1 - i] = temp;
		i++;
	}
	return (res);
}

char	*ft_convert(int nbr, char *base_to)
{
	char	*res;
	int		len;
	int		i;
	int		sign;

	i = 0;
	if (nbr < 0)
	{
		sign = -1;
		nbr = nbr * -1;
	}
	len = base_len(base_to);
	res = malloc(1 * 36);
	if (!res)
		return (NULL);
	while (nbr)
	{
		res[i] = base_to[nbr % len];
		nbr = nbr / len;
		i++;
	}
	if (sign < 0)
		res[i] = '-';
	res[++i] = '\0';
	return (rev(res));
}
