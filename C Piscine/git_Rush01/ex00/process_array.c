/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-r <cgomez-r@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:55:12 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/22 16:48:47 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define N 4

int	is_valid_row_left(int square[N][N], int row, int constraints[N]);
int	is_valid_row_right(int square[N][N], int row, int constraints[N]);
int	is_valid_column_up(int square[N][N], int col, int constraints[N]);
int	is_valid_column_down(int square[N][N], int col, int constraints[N]);
int	solve_cell(int matrix[N][N], int row, int col, int input[N][N]);

void	ini_matrix(int matrix[N][N])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_matrix(int matrix[N][N])
{
	char	num;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			num = matrix[i][j] + '0';
			write(1, &num, 1);
			if (j < N - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	solve(int matrix[N][N], int row, int col, int input[N][N])
{
	int	num;
	int	i;

	i = 0;
	if (row == N)
	{
		while (i < N)
		{
			if (!(is_valid_column_up(matrix, i, input[0])))
				return (0);
			if (!(is_valid_column_down(matrix, i, input[1])))
				return (0);
			i++;
		}
		return (1);
	}
	if (col == N)
	{
		if (!(is_valid_row_left(matrix, row, input[2])))
			return (0);
		if (!(is_valid_row_right(matrix, row, input[3])))
			return (0);
		return (solve(matrix, row + 1, 0, input));
	}
	return (solve_cell(matrix, row, col, input));
}

void	process_matrix(int input[N][N])
{
	int	matrix[N][N];

	ini_matrix(matrix);
	if (solve(matrix, 0, 0, input))
		print_matrix(matrix);
	else
		write(1, "ERROR\n", 6);
}
