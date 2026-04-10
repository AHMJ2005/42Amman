/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prase_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:22:39 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/10 18:27:18 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	prase_input(char *arg, int *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		if (arg[i] >= '1' && arg[i] <= '4')
		{
			if (j >= 16)
				return (0);
			input[j++] = arg[i] - '0';
			i++;
			if (arg[i] != ' ' && arg[i] != '\0')
				return (0);
			else if (arg[i] == ' ')
				i++;
			else
				return (0);
		}
	}
	return (j == 16);
}
