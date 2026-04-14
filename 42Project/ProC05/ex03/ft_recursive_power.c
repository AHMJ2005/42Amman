/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 16:09:46 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/13 16:26:05 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	pow;

	pow = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power != 0)
	{
		pow = nb * ft_recursive_power(nb, power - 1);
	}
	return (pow);
}
