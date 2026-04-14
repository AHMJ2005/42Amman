/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:04:19 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/13 14:27:15 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	size(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*s;
	char	*f;
	char	*st;
	int		sizes;

	sizes = size(to_find);
	if (sizes == 0)
		return (str);
	while (*str)
	{
		s = str;
		f = to_find;
		while (*f && *f == *s)
		{
			f++;
			s++;
		}
		if (*f == '\0')
		{
			st = s - sizes;
			return (st);
		}
		str++;
	}
	return (NULL);
}
