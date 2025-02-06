/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:20:12 by lsanchez          #+#    #+#             */
/*   Updated: 2024/09/24 21:48:59 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	n;

	if (nb == -2147483648)
	{
		write(fd, &"-2", 2);
		ft_putnbr_fd(147483648, fd);
	}
	else if (nb < 10 && nb >= 0)
	{
		n = '0' + nb % 10;
		write(fd, &n, 1);
	}
	else if (nb < 0)
	{
		write(fd, &"-", 1);
		ft_putnbr_fd(-nb, fd);
	}
	else
	{
		n = '0' + nb % 10;
		nb = nb / 10;
		ft_putnbr_fd(nb, fd);
		write(fd, &n, 1);
	}
}
