/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_views_partial.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:16:07 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/10 18:32:52 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible_row_left(int row, int **shap);
int	count_visible_row_right(int row, int **shap);
int	count_visible_col_top(int col, int **shap);
int	count_visible_col_bottom(int col, int **shap);

int	check_row(int row, int **shap, int *input)
{
	int	i;
	int	filled;

	i = 0;
	filled = 1;
	while (i < 4)
	{
		if (shap[row][i++] == 0)
			filled = 0;
		if (filled)
		{
			if (count_visible_row_left(row, shap) != input[8 + row])
				return (0);
			if (count_visible_row_right(row, shap) != input[12 + row])
				return (0);
		}
	}
	return (1);
}

int	check_col(int col, int **shap, int *input)
{
	int	i;
	int	filled;

	i = 0;
	filled = 1;
	while (i < 4)
	{
		if (shap[col][i++] == 0)
			filled = 0;
		if (filled)
		{
			if (count_visible_col_top(col, shap) != input[col])
				return (0);
			if (count_visible_col_bottom(col, shap) != input[4 + col])
				return (0);
		}
	}
	return (1);
}

int	check_viwes_partial(int row, int col, int **shap, int *input)
{
	if (!check_row(row, shap, input))
		return (0);
	if (!check_col(col, shap, input))
		return (0);
	return (1);
}
