/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 09:08:12 by aalbess           #+#    #+#             */
/*   Updated: 2025/09/29 13:01:48 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count(char *str, char *charset)
{
	int	i;
	int	counter;
	int	in;

	i = 0;
	in = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset))
			in = 0;
		else if (!in)
		{
			in = 1;
			counter++;
		}
		i++;
	}
	return (counter);
}

char	*dynamic(char *str, int start, int end)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(sizeof(char) * (end - start + 1));
	if (!p)
		return (NULL);
	while (start < end)
	{
		p[i++] = str[start];
		start++;
	}
	p[i] = '\0';
	return (p);
}

void	fill(char **p, char *str, char *charset)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset))
			i++;
		else
		{
			start = i;
			while (str[i] && !is_sep(str[i], charset))
				i++;
			p[j++] = dynamic(str, start, i);
		}
	}
	p[j] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	char	**p;
	int		size;

	size = count(str, charset);
	p = malloc(sizeof(char *) * size + 1);
	if (!p)
		return (NULL);
	fill(p, str, charset);
	return (p);
}
int main()
{
        char *str = "M&gt;,w&amp;SmTH!idn0;cZh5";
        char *charset = "9odW5&gt;QIKEi!hM?4G[^";
        char **p;
        p = ft_split(str, charset);
        int i =0;
        while (p[i] != NULL)
        {
                printf("%s\n", p[i]);
                i++;
        }
        return(0);
}
