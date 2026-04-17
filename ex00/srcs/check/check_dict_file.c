/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:53:51 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/17 17:54:33 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 4096

int	check_dict_file(char *dict)
{
	int	fd;
	char	buf[BUF_SIZE];
	ssize_t	bytes_read;

	fd = open(dict, O_RDONLY);
	if (fd == -1)
		return (0);
	bytes_read = read(fd, buf, BUF_SIZE);
	if (bytes_read <= 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
