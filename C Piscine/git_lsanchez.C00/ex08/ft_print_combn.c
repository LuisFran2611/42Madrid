/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:32:04 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/11 20:10:44 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	putchar(char c)
{
	write (1, &c, 1);
}

void	pintar(int i)
{
	char	n;

	if (i < 10)
	{
		n = '0' + i;
		putchar (n);
	}
	else
	{
		n = '0' + (i % 10);
		i = i / 10;
		pintar (i);
		putchar (n);
	}
}

void	ft_print_combn(int n)
{
	int	mx;
	int	num;

	if (n < 10 && n > 0)
	{
		mx = 1;
		num = 0;
		while (n != 0)
		{
			mx = mx * 10;
			n--;
		}
		while (num < mx)
		{
			pintar (num);
			if (num != mx - 1)
			{
				putchar (',');
				putchar (' ');
			}
			num++;
		}
	}
}
