/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:31:19 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/29 18:59:03 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_operations.h"
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

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

int	ft_operation(int n1, int n2, int (*f)(int, int))
{
	return (f(n1, n2));
}

int	ft_calculator(int n1, char *operation, int n2)
{
	if (ft_strlen(operation) != 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (*operation == '+')
		return (ft_operation(n1, n2, &ft_sum));
	else if (*operation == '-')
		return (ft_operation(n1, n2, &ft_resta));
	else if (*operation == '*')
		return (ft_operation(n1, n2, &ft_mul));
	else if (*operation == '/')
		return (ft_operation(n1, n2, &ft_div));
	else if (*operation == '%')
		return (ft_operation(n1, n2, &ft_modulo));
	write(1, "0\n", 2);
	return (0);
}

int	main(int argc, char **argv)
{
	int	n[2];
	int	result;

	if (argc == 4)
	{
		n[0] = ft_atoi(argv[1]);
		n[1] = ft_atoi(argv[3]);
		result = ft_calculator(n[0], argv[2], n[1]);
		return (result);
	}
	else
		write(1, "0\n", 2);
}
