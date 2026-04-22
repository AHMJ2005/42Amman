/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:36:13 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/22 13:51:16 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

char	*read_line(int fd)
{
	int		i;
	int		size;
	char	*buff;
	char	c;

	i = 0;
	size = 5000;
	buff = malloc(sizeof(char) * size);
	if (!buff)
		return (NULL);
	while (read(fd, &c, 1) && c != '\n')
	{
		if (i >= size - 1)
		{
			return (NULL);
		}
		buff[i++] = c;
	}
	if (i == 0 && c != '\n')
		return (free(buff), NULL);
	buff[i] = '\0';
	return (buff);
}
