/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:50:04 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/15 17:39:31 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
/*int main()
{
	ft_putnbr(-2147483648);
	putchar('\n');
	ft_putnbr(-42);
        putchar('\n');
	ft_putnbr(0);
        putchar('\n');
	ft_putnbr(42);
        putchar('\n');
	ft_putnbr(2147483647);
        putchar('\n');
}*/
