/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_placment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:19:38 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/10 18:22:18 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_placment(int row, int col, int num, int **shap)
{
	int	i;

	i = 0;
	while ()
	{
		if (shap[row][i] == num || shap[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}
