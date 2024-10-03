/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:29:07 by lsanchez          #+#    #+#             */
/*   Updated: 2024/10/03 19:23:16 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_hex(unsigned int num, int *length, char x)
{
	char	hex_num[25];
	char	*base_hex;
	int		i;

	if (x == 'X')
		base_hex = "0123456789ABCDEF";
	else
		base_hex = "0123456789abcdef";
	i = 0;
	if (x == 0)
		ft_print_char('0', length);
	while (num != 0)
	{
		hex_num[i] = base_hex[num % 16];
		num = num / 16;
		i++;
	}
	while (i--)
		ft_print_char(hex_num[i], length);
}
