/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:29:10 by lsanchez          #+#    #+#             */
/*   Updated: 2025/02/15 10:24:16 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_int(int num, int *length)
{
	char	n;

	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
	}
	else if (num < 10 && num >= 0)
	{
		n = '0' + num % 10;
		ft_print_char(n, length);
	}
	else if (num < 0)
	{
		ft_print_char('-', length);
		ft_print_int(-num, length);
	}
	else
	{
		n = '0' + num % 10;
		num = num / 10;
		ft_print_int(num, length);
		ft_print_char(n, length);
	}
}
