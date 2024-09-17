/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-r <cgomez-r@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:17:13 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/18 18:48:00 by cgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 4

int	solve(int matrix[N][N], int row, int col, int input[N][N]);
int	not_dupe(int square[N][N], int row, int col, int num);

int	solve_cell(int matrix[N][N], int row, int col, int input[N][N])
{
	int	num;

	num = 1;
	while (num <= N)
	{
		if (not_dupe(matrix, row, col, num))
		{
			matrix[row][col] = num;
			if (solve(matrix, row, col + 1, input))
				return (1);
			matrix[row][col] = 0;
		}
		num++;
	}
	return (0);
}
