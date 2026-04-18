/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:16:07 by aalbess           #+#    #+#             */
/*   Updated: 2025/09/28 09:05:13 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	length;
	int	between;
	int	*p;

	length = max - min;
	if (min >= max)
	{
		p = NULL;
		return (p);
	}
	p = malloc(4 * length);
	if (!p)
		return (NULL);
	i = 0;
	between = min;
	while (i < length)
	{
		p[i] = between + i;
		i++;
	}
	return (p);
}
