/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:57:51 by lsanchez          #+#    #+#             */
/*   Updated: 2025/04/13 11:05:51 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_hex(unsigned int num, int *length, char x)
{
	char	hex_char;
	char	*base_hex;

	if (x == 'X')
		base_hex = "0123456789ABCDEF";
	else
		base_hex = "0123456789abcdef";
	hex_char = base_hex[num % 16];
	if (num >= 16)
	{
		num = num / 16;
		ft_print_hex(num, length, x);
	}
	ft_print_char(hex_char, length);
}
