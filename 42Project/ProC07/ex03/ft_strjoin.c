/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 09:27:02 by aalbess           #+#    #+#             */
/*   Updated: 2025/09/28 12:23:04 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	size_of(int size, char **strs, char *sep)
{
	int	sep_len;
	int	i;
	int	j;
	int	counter;

	sep_len = 0;
	while (sep[sep_len] != '\0')
		sep_len++;
	j = 0;
	counter = 0;
	while (j < size)
	{
		i = 0;
		while (strs[j][i] != '\0')
		{
			counter++;
			i++;
		}
		j++;
	}
	counter += sep_len * (size - 1);
	return (counter + 1);
}

void	ft_seperator(char *p, int *c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		p[*c] = sep[i];
		(*c)++;
		i++;
	}
}

char	*empty(void)
{
	char	*result;

	result = malloc(sizeof(char *) * 1);
	if (result)
		result[0] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*p;
	int		i;
	int		j;
	int		c;

	if (size == 0)
		return (empty());
	j = 0;
	c = 0;
	p = malloc(1 * size_of(size, strs, sep));
	while (j < size)
	{
		i = 0;
		while (strs[j][i] != '\0')
		{
			p[c] = strs[j][i];
			i++;
			c++;
		}
		if (c != (size_of(size, strs, sep) - 1))
			ft_seperator(p, &c, sep);
		j++;
	}
	p[c] = '\0';
	return (p);
}
