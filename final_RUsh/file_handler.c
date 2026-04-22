/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:49:49 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/21 17:52:12 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

char	*file_read(char *file_to_read)
{
	int		file;
	char	*ret;

	file = open(file_to_read, O_RDONLY);
	if (file == -1)
		return (NULL);
	ret = malloc(5000 * sizeof(char));
	if (ret != NULL)
		if (!read(file, ret, 5000))
			return (NULL);
	close(file);
	return (ret);
}
