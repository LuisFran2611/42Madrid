/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:30:40 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/29 15:24:11 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copia;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	size++;
	copia = (char *)malloc (size * sizeof(char));
	if (copia == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copia[i] = src[i];
		i++;
	}
	return (copia);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*cadenas;
	int			j;

	cadenas = (t_stock_str *)malloc((ac + 1) * sizeof (t_stock_str));
	if (cadenas == NULL)
		return (NULL);
	j = 0;
	while (j < ac)
	{
		cadenas[j].size = ft_strlen(av[j]);
		cadenas[j].str = av[j];
		cadenas[j].copy = ft_strdup(av[j]);
		if (cadenas[j].copy == NULL)
		{
			while (j-- > 0)
				free(cadenas[j].copy);
			free(cadenas);
			return (NULL);
		}
		j++;
	}
	cadenas[j].str = NULL;
	return (cadenas);
}
