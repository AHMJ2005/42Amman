/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:48:33 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/10 18:38:23 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	solve(int row, int col, int **shap, int *input)
{
	int	num;
	int	i;

	if (row == 4)
		return (check_viwes(shap, input));
	if (col == 4)
		return (solve(row + 1), 0, shap, input);
	num = 1;
	i = 0;
	while (num <= 4)
	{
		if (is_valid_placment(row, col, num, shap))
		{
			shap[row][col] = num;
			if (check_viwes__partial(row, col, shap, input)
				&& solve(row, col + 1, shap, input))
				return (1);
			shap[row][col] = 0;
		}
		num++;
	}
}
