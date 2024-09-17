/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:07:50 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/19 11:18:40 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	resultado;
	int	sig;

	resultado = 0;
	sig = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str == '-' || *str == '+')
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

/*int main()
{
	char  c[] =" ---+--+1234ab567";
	printf("%d",ft_atoi(c));
	return 0;
}*/
