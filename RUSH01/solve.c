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

int	is_valid_placement(int row, int col, int num, int **shap);
int	check_viwes(int **shap, int *input);
int	check_viwes_partial(int row, int col, int **shap, int *input);

int	solve(int row, int col, int **shap, int *input)
{
	int	num;

	if (row == 4)
		return (check_viwes(shap, input));
	if (col == 4)
		return (solve(row + 1, 0, shap, input));
	num = 1;
	while (num <= 4)
	{
		if (is_valid_placement(row, col, num, shap))
		{
			shap[row][col] = num;
			if (check_viwes_partial(row, col, shap, input)
				&& solve(row, col + 1, shap, input))
				return (1);
			shap[row][col] = 0;
		}
		num++;
	}
	return (0);
}
