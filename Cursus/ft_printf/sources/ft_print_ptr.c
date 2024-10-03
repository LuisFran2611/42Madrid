/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:29:13 by lsanchez          #+#    #+#             */
/*   Updated: 2024/10/03 19:23:16 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_ptr(size_t ptr, int *length)
{
	char	hex_num[25];
	char	*base_hex;
	int		i;

	base_hex = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*length) += 2;
	while (ptr != 0)
	{
		hex_num[i] = base_hex[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
		ft_print_char(hex_num[i], length);
}
