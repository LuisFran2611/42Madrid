/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:11:25 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/29 18:42:32 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "ft_putnbr.h"

int	ft_mul(int n1, int n2)
{
	int	mul;

	mul = n1 * n2;
	ft_putnbr(mul);
	return (write(1, "\n", 1), mul);
}

int	ft_sum(int n1, int n2)
{
	int	sum;

	sum = n1 + n2;
	ft_putnbr(sum);
	return (write(1, "\n", 1), sum);
}

int	ft_resta(int n1, int n2)
{
	int	rest;

	rest = n1 - n2;
	ft_putnbr(rest);
	return (write(1, "\n", 1), rest);
}

int	ft_div(int n1, int n2)
{
	int	div;

	if (n2 != 0)
	{
		div = n1 / n2;
		ft_putnbr(div);
		return (write(1, "\n", 1), div);
	}
	write(1, "Stop : division by zero\n", 24);
	return (0);
}

int	ft_modulo(int n1, int n2)
{
	int	mod;

	if (n2 != 0)
	{
		mod = n1 % n2;
		ft_putnbr(mod);
		return (write(1, "\n", 1), mod);
	}
	write(1, "Stop : modulo by zero\n", 22);
	return (0);
}
