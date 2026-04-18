/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:47:33 by aalbess           #+#    #+#             */
/*   Updated: 2025/09/28 16:09:28 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = -1;
		while (argv[j][++i] != '\0')
			write(1, &argv[j][i], 1);
		j++;
		write(1, "\n", 1);
	}
	return (0);
}
