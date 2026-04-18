/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:28:31 by aalbess           #+#    #+#             */
/*   Updated: 2025/09/28 16:09:11 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	(void)argc;
	i = -1;
	while (argv[0][++i] != '\0')
		write(1, &argv[0][i], 1);
	write(1, "\n", 1);
	return (0);
}
