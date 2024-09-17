/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:55:18 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/11 20:54:37 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_putchar.h"
#include "rush00.h"

void	choose_char( int c_x, int c_y, int x, int y)
{
	if (c_x == x)
	{
		ft_putchar ('\n');
	}
	else if ((c_x == 0 || c_x == x - 1) && (c_y == 0 || c_y == y - 1))
	{
		ft_putchar ('o');
	}
	else if (c_y == 0 || c_y == y - 1)
	{
		ft_putchar ('-');
	}
	else if (c_x == 0 || c_x == x - 1)
	{
		ft_putchar ('|');
	}
	else
	{
		ft_putchar (' ');
	}
}

void	rush(int x, int y)
{
	int	c_x;
	int	c_y;

	c_x = 0;
	c_y = 0;
	if (!(x <= 0 || y <= 0))
	{
		while (c_y < y)
		{
			c_x = 0;
			while (c_x <= x)
			{
				choose_char (c_x, c_y, x, y);
				c_x++;
			}
			c_y++;
		}
	}
}
