/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proces_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:24:56 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/25 22:28:42 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "dict_search.h"

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

char	*add_zero(char *str, int size, int group)
{
	char	*zero_str;
	int		i;
	int		j;

	i = (group * 3) - size;
	j = 0;
	zero_str = (char *)malloc(group * 3);
	while (i)
	{
		zero_str[j] = '0';
		j++;
		i--;
	}
	while (str[i])
	{
		zero_str[j] = str[i];
		i++;
		j++;
	}
	return (zero_str);
}

void	ft_rev_matrix_tab(char **tab, int size)
{
	char	*tmp;
	int		i;
	int		j;

	if (tab == NULL || size <= 0)
		return ;
	i = 0;
	j = size - 1;
	while (i < (size / 2))
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		j--;
		i++;
	}
}

void	init_matrix(char **matrix, char *str, int group)
{
	int	i;
	int	j;

	i = 0;
	while (i < group)
	{
		matrix[i] = (char *)malloc(4);
		j = 0;
		while (j < 3)
		{
			matrix[i][j] = *str;
			str++;
			j++;
		}
		matrix[i][j] = '\0';
		i++;
	}
	matrix[i] = (char *)malloc(1);
	matrix[i][0] = '\0';
}

void	proces_num(char *str, char *dic)
{
	int		size;
	int		group;
	char	**matrix;

	size = ft_strlen(str);
	group = size / 3;
	if (size % 3)
		group++;
	str = add_zero(str, size, group);
	matrix = (char **)malloc((group + 1) * sizeof(char *));
	init_matrix(matrix, str, group);
	ft_rev_matrix_tab(matrix, group);
	conv_dic(matrix, group, dic);
	free(matrix);
}
