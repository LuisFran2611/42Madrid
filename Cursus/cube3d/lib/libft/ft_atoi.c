/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:34:00 by lsanchez          #+#    #+#             */
/*   Updated: 2024/09/27 08:35:19 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	resultado;
	int	sig;

	resultado = 0;
	sig = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig = sig * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		resultado = (resultado * 10) + (*str - '0');
		str++;
	}
	return (resultado * sig);
}
