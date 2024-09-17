/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:43:29 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/29 15:23:52 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	write(1, str, length);
}

void	putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	n;

	if (nb == -2147483648)
	{
		write (1, &"-2", 2);
		ft_putnbr(147483648);
	}
	else if (nb < 10 && nb >= 0)
	{
		n = '0' + nb % 10;
		putchar (n);
	}
	else if (nb < 0)
	{
		putchar ('-');
		ft_putnbr (-nb);
	}
	else
	{
		n = '0' + nb % 10;
		nb = nb / 10;
		ft_putnbr(nb);
		putchar(n);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr (par[i].str);
		write (1, "\n", 1);
		ft_putnbr(par[i].size);
		write (1, "\n", 1);
		ft_putstr (par[i].copy);
		write (1, "\n", 1);
		i++;
	}
}
