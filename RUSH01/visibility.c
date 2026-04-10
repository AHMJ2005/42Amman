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

int	count_visible_row_left(int row, int **shap)
{
	int	max;
	int	i;
	int	count;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (shap[row][i] > max)
		{
			max = shap[row][i];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_visible_row_right(int row, int **shap)
{
	int	max;
	int	i;
	int	count;

	max = 0;
	count = 0;
	i = 3;
	while (i >= 0)
	{
		if (shap[row][i] > max)
		{
			max = shap[row][i];
			count++;
		}
		i--;
	}
	return (count);
}

int	count_visible_col_top(int col, int **shap)
{
	int	max;
	int	i;
	int	count;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4) // تصحيح الشرط هنا من > إلى <
	{
		if (shap[i][col] > max)
		{
			max = shap[i][col];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_visible_col_bottom(int col, int **shap)
{
	int	max;
	int	i;
	int	count;

	max = 0;
	count = 0;
	i = 3;
	while (i >= 0)
	{
		if (shap[i][col] > max)
		{
			max = shap[i][col];
			count++;
		}
		i--;
	}
	return (count);
}
