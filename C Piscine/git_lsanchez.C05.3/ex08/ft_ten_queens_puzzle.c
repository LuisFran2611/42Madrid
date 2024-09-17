/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:59:58 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/19 18:54:34 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ini_queens(int reinas[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		reinas[i] = 0;
		i++;
	}
}

int	check_ok(int reinas[10], int row, int col)
{
	int	qcol;
	int	i;

	i = 0;
	while (i < row)
	{
		qcol = reinas[i];
		if (qcol == col || (qcol - col) == (i - row)
			|| (qcol - col) == (row - i))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	print_board(int reinas[10])
{
	char	n;
	int		i;

	i = 0;
	while (i < 10)
	{
		n = reinas[i] + '0';
		write(1, &n, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ten_queens_recursive(int reinas[10], int row)
{
	int	col;
	int	sol;

	if (row == 10)
	{
		print_board (reinas);
		return (1);
	}
	sol = 0;
	col = 0;
	while (col < 10)
	{
		if (check_ok (reinas, row, col))
		{
			reinas[row] = col;
			sol += ten_queens_recursive (reinas, row + 1);
		}
		col++;
	}
	return (sol);
}

int	ft_ten_queens_puzzle(void)
{
	int	sol;
	int	reinas[10];

	ini_queens (reinas);
	sol = ten_queens_recursive (reinas, 0);
	return (sol);
}

/*int	main()
{
	int	n;
	n = ft_ten_queens_puzzle();
	printf("%d",n);
	return 0;
}*/
