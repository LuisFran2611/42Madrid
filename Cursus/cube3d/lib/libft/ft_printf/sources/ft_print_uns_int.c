/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:29:19 by lsanchez          #+#    #+#             */
/*   Updated: 2025/02/15 10:23:52 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_uns_int(unsigned int num, int *length)
{
	if (num >= 10)
		ft_print_uns_int(num / 10, length);
	ft_print_char(num % 10 + '0', length);
}
