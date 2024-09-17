/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:31:40 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/11 19:20:16 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print(int i, int s, int k)
{
	char	n1;
	char	n2;
	char	n3;

	n1 = '0' + i;
	n2 = '0' + s;
	n3 = '0' + k;
	write (1, &n1, 1);
	write (1, &n2, 1);
	write (1, &n3, 1);
	if (i != 7)
	{
		write (1, ",", 1);
		write (1, " ", 1);
	}
}

void	ft_print_comb(void)
{
	int	i[3];

	i[0] = 0;
	i[1] = 1;
	i[2] = 2;
	while (i[0] < 10)
	{
		while (i[1] < 10)
		{
			while (i[2] < 10)
			{
				if (!(i[0] == i[1] || i[1] == i[2] || i[1] == i[0]))
				{
					ft_print (i[0], i[1], i[2]);
				}
				i[2]++;
			}
			i[1]++;
			i[2] = i[1] +1;
		}
		i[0]++;
		i[1] = i[0] + 1;
		i[2] = i[1] + 1;
	}
}
