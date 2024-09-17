/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:38:49 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/19 11:25:08 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	cont_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[j] == '+'
				|| base[j] == '-' || base[j] == ' ')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (i);
}

int	buscar_caracter(const char *cadena, char caracter)
{
	int	indice;

	indice = 0;
	while (cadena[indice] != '\0')
	{
		if (cadena[indice] == caracter)
		{
			return (indice);
		}
		indice++;
	}
	return (-1);
}

int	get_int(char *str, char *base, int n)
{
	int	indice;
	int	resultado;

	resultado = 0;
	indice = 0;
	while (*str && indice != (-1))
	{
		indice = buscar_caracter (base, *str);
		if (indice != (-1))
		{
			resultado = (resultado * n) + indice;
		}
		str++;
	}
	return (resultado);
}

int	ft_atoi_base(char *str, char *base)
{
	int	n;
	int	sig;

	sig = 1;
	n = cont_base (base);
	if (n > 1)
	{
		while (*str == ' ' || (*str == '\t' && *str <= '\r'))
			str++;
		while (*str == '-' || *str == '+')
		{
			if (*str == '-')
				sig = sig * (-1);
			str++;
		}
		n = get_int (str, base, n);
	}
	return (n * sig);
}

/*int main()
{
	int n;
	n = ft_atoi_base("bdf","abcdefghij");
	printf("%d",n);
	return 1;
}*/
