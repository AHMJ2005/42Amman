/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:34:34 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/22 16:34:38 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	char	*it;

	it = str;
	while (*it != '\0')
	{
		write(1, it, 1);
		it++;
	}
}

int	prep_num(int num)
{
	if (num < 0)
	{
		num *= -1;
	}
	return (num);
}

void	print_num(int digits[], int len)
{
	int		counter;
	char	out;

	counter = len - 1;
	while (counter >= 0)
	{
		out = digits[counter] + '0';
		write(1, &out, 1);
		counter--;
	}
	if (len == 0)
	{
		out = '0';
		write(1, &out, 1);
	}
}

void	ft_putnbr(int nb)
{
	char	zero;
	int		len;
	int		digits[21];

	zero = '0';
	len = 0;
	while (nb != 0)
	{
		digits[len++] = prep_num(nb % 10);
		nb /= 10;
	}
	print_num(digits, len);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	ctr;

	ctr = 0;
	while (par[ctr].str != 0)
	{
		ft_putstr(par[ctr].str);
		write(1, "\n", 1);
		ft_putnbr(par[ctr].size);
		write(1, "\n", 1);
		ft_putstr(par[ctr].copy);
		write(1, "\n", 1);
		ctr++;
	}
}
