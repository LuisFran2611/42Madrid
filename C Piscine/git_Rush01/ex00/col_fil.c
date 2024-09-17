/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_fil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-r <cgomez-r@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:46:38 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/18 18:49:05 by cgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define N 4

int	is_valid_row_left(int square[N][N], int row, int constraints[N])
{
	int	max_seen;
	int	visible_count;
	int	j;

	max_seen = 0;
	visible_count = 0;
	j = 0;
	while (j < N)
	{
		if (square[row][j] > max_seen)
		{
			max_seen = square[row][j];
			visible_count++;
		}
		j++;
	}
	if (visible_count == constraints[row])
		return (1);
	return (0);
}

int	is_valid_column_up(int square[N][N], int col, int constraints[N])
{
	int	max_seen;
	int	visible_count;
	int	i;

	max_seen = 0;
	visible_count = 0;
	i = 0;
	while (i < N)
	{
		if (square[i][col] > max_seen)
		{
			max_seen = square[i][col];
			visible_count++;
		}
		i++;
	}
	if (visible_count == constraints[col])
		return (1);
	return (0);
}

int	is_valid_row_right(int square[N][N], int row, int constraints[N])
{
	int	max_seen;
	int	visible_count;
	int	j;

	max_seen = 0;
	visible_count = 0;
	j = 0;
	while (j < N)
	{
		if (square[row][N - 1 - j] > max_seen)
		{
			max_seen = square[row][N - 1 - j];
			visible_count++;
		}
		j++;
	}
	if (visible_count == constraints[row])
		return (1);
	return (0);
}

int	is_valid_column_down(int square[N][N], int col, int constraints[N])
{
	int	max_seen;
	int	visible_count;
	int	i;

	max_seen = 0;
	visible_count = 0;
	i = 0;
	while (i < N)
	{
		if (square[N - 1 - i][col] > max_seen)
		{
			max_seen = square[N - 1 - i][col];
			visible_count++;
		}
		i++;
	}
	if (visible_count == constraints[col])
		return (1);
	return (0);
}

int	not_dupe(int square[N][N], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (square[row][i] == num || square[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}
