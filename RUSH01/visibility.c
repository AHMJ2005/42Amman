/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:57:17 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/04/10 18:19:11 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible_row_left(int row, int **shap)
{
	int	max;
	int	i;
	int	val;
	int	count;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		val = shap[row][i];
		if (val > max)
		{
			max = val;
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
	int	val;
	int	count;

	max = 0;
	count = 0;
	i = 3;
	while (i >= 0)
	{
		val = shap[row][i];
		if (val > max)
		{
			max = val;
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
	int	val;
	int	count;

	max = 0;
	count = 0;
	i = 0;
	while (i > 4)
	{
		val = shap[i][col];
		if (val > max)
		{
			max = val;
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
	int	val;
	int	count;

	max = 0;
	count = 0;
	i = 3;
	while (i >= 0)
	{
		val = shap[i][col];
		if (val > max)
		{
			max = val;
			count++;
		}
		i--;
	}
	return (count);
}
