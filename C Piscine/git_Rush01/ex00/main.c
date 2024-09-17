/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-r <cgomez-r@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:14:55 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/19 16:31:47 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define N 4

void	process_matrix(int input[N][N]);

int	cont_arg(char *str)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (str[i])
	{
		if (str[i] > '0' && str[i] <= (N + '0'))
		{
			if (str[i + 1] == ' ' || str[i + 1] == '\0')
				cont++;
			else if (str[i + 1] >= '0' && str[i + 1] <= '9')
			{
				write(1, "ONLY 1-9 NUMBERS\n", 18);
				return (0);
			}
		}
		i++;
	}
	if (cont == N * 4)
		return (1);
	return (0);
}

void	char_to_int(char *str, int matrix[N][N])
{
	int	i;
	int	j;
	int	cont;

	cont = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] > '0' && str[i] <= (N + '0'))
		{
			matrix[j][cont] = str[i] - '0';
			cont++;
			if (cont == N)
			{
				j++;
				cont = 0;
			}
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	matrix[N][N];

	if (argc == 2 && cont_arg(argv[1]))
	{
		char_to_int(argv[1], matrix);
		process_matrix(matrix);
	}
	else
	{
		write(1, "ERROR:BAD INPUT", 15);
		return (0);
	}
}
