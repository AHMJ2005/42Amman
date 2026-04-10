/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_views.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:03:15 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/10 18:29:27 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_row_left(int row, int **shap);
int	count_row_right(int row, int **shap);
int	count_col_top(int col, int **shap);
int	count_col_bottom(int col, int **shap);

int	check_views(int **shap, int *input)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (count_col_top(i, shap) != input[i])
			return (0);
		if (count_col_bottom(i, shap) != input[i + 4])
			return (0);
		if (count_row_left(i, shap) != input[i + 8])
			return (0);
		if (count_row_right(i, shap) != input[i + 12])
			return (0);
		i++;
	}
	return (0);
}
