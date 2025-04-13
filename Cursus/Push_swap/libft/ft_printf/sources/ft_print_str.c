/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:29:15 by lsanchez          #+#    #+#             */
/*   Updated: 2025/04/13 11:06:27 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_str(char *str, int *length)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	while (str[i] != '\0')
	{
		ft_print_char(str[i], length);
		i++;
	}
}
