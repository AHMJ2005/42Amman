/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:43:23 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/21 19:36:22 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*it;

	it = dest;
	while (n && *src)
	{
		n--;
		*it = *src;
		src++;
		it++;
	}
	while (n--)
	{
		*it++ = '\0';
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (*str != 0)
	{
		ret++;
		str++;
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
