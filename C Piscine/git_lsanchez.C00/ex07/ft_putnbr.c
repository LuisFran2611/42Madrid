/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:50:04 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/15 13:40:26 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	s;
	char	n;
	if(n == -2147483648)
	{
		write (1, &"-2147483648", 11);
		return ;
	}
	if (nb < 10 && nb >= 0)
	{
		s = '0' + nb % 10;
		putchar (s);
	}
	else
	{
		if (nb < 0)
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
}
