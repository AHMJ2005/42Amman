/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:36:03 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/22 16:24:17 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

int	ft_atoi_header(char *str, int len)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i < len)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int	parse_header(int fd, char **key, int *nb_rows)
{
	char	buf[100];
	int		i;

	i = 0;
	while (read(fd, &buf[i], 1) && buf[i] != '\n' && i < 99)
		i++;
	if (i < 4)
		return (0);
	(*key)[0] = buf[i - 3];
	(*key)[1] = buf[i - 2];
	(*key)[2] = buf[i - 1];
	*nb_rows = ft_atoi_header(buf, i - 3);
	return (1);
}

int	is_line_valid(char *line, int *line_len, char *key)
{
	int	j;

	j = 0;
	if (!line)
		return (0);
	while (line[j] && line[j] != '\n')
	{
		if (line[j] != key[0] && line[j] != key[1])
			return (0);
		j++;
	}
	if (*line_len == -1)
		*line_len = j;
	if (j != *line_len || j == 0)
		return (0);
	return (1);
}

char	**read_and_parse(char *fileN, char **key)
{
	int		fd;
	int		nb_rows;
	int		line_len;
	char	**map;
	int		i;

	fd = open(fileN, O_RDONLY);
	if (fd < 0 || !parse_header(fd, key, &nb_rows))
		return (NULL);
	map = malloc(sizeof(char *) * (nb_rows + 1));
	if (!map)
		return (NULL);
	i = 0;
	line_len = -1;
	while (i < nb_rows)
	{
		map[i] = read_line(fd);
		if (!is_line_valid(map[i], &line_len, *key))
			return (NULL);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
/*
int	is_line_valid(char *line, int *line_len, char *key)
{
	int	j;
	int	ok;

	j = 0;
	if (!line)
		return (0);
	while (line[j] && line[j] != '\n')
	{
		if (line[j] != key[0] && line[j] != key[1])
			return (0);
		j++;
	}
	if (*line_len == -1)
		*line_len = j;
	ok = line[j] == '\0' || line[j] == '\n' ? j == *line_len : 0;
	return (ok);
}

char	**read_and_parse(char *fileN, char **key)
{
	int		fd;
	int		nb_rows;
	int		line_len;
	char	**map;
	int		i;

	fd = open(fileN, O_RDONLY);
	if (fd < 0 || !parse_header(fd, key, &nb_rows))
		return (NULL);
	map = malloc(sizeof(char *) * (nb_rows + 1));
	i = 0;
	line_len = -1;
	while (map && i < nb_rows)
	{
		map[i] = read_line(fd);
		if (!is_line_valid(map[i++], &line_len, *key))
			return (NULL);
	}
	if (map)
		map[i] = NULL;
	close(fd);
	return (map);
}*/
/*
int	is_line_valid(char *line, int *line_len, char *key)
{
	int	j;

	j = 0;
	if (!line)
		return (0);
	while (line[j] && line[j] != '\n')
	{
		if (line[j] != key[0] && line[j] != key[1])
			return (0);
		j++;
	}
	if (*line_len == -1)
		*line_len = j;
	if (j != *line_len || j == 0)
		return (0);
	return (1);
}

char	**read_and_parse(char *fileN, char **key)
{
	int		fd;
	int		nb_rows;
	int		line_len;
	char	**map;
	int		i;

	fd = open(fileN, O_RDONLY);
	if (fd < 0 || !parse_header(fd, key, &nb_rows))
		return (NULL);
	map = malloc(sizeof(char *) * (nb_rows + 1));
	if (!map)
		return (NULL);
	i = 0;
	line_len = -1;
	while (i < nb_rows)
	{
		map[i] = read_line(fd);
		if (!is_line_valid(map[i], &line_len, *key))
		{
			close(fd);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}*/
/*
int	is_line_valid(char *line, int *line_len, char *key)
{
	int	j;

	j = 0;
	if (!line)
		return (0);
	while (line[j])
	{
		if (line[j] != key[0] && line[j] != key[1])
			return (0);
		j++;
	}
	if (*line_len == -1)
		*line_len = j;
	if (j != *line_len || j == 0)
		return (0);
	return (1);
}

char	**read_and_parse(char *fileN, char **key)
{
	int		fd;
	int		nb_rows;
	char	**map;
	int		i;
	int		line_len;

	fd = open(fileN, O_RDONLY);
	if (fd < 0 || !parse_header(fd, key, &nb_rows))
		return (NULL);
	map = malloc(sizeof(char *) * (nb_rows + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < nb_rows)
	{
		map[i] = read_line(fd);
		if (!map[i])
			return (NULL);
		line_len = -1;
		if (!is_line_valid(map[i], &line_len, *key))
			return (NULL);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}*/
