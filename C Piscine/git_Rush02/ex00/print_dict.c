/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:28:27 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/25 22:35:59 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "proces_dict.h"

int	char_index(char *buffer, int group, char **matrix)
{
	char	*dec;
	int		i;

	dec = (char *)malloc((group * 3) + 2);
	i = 0;
	dec[i] = '1';
	while (i <= group * 3)
	{
		i++;
		dec[i] = '0';
	}
	dec[i] = '\0';
	if (!is_all_zero(matrix, group, buffer, 0))
	{
		if (ft_strstr(buffer, dec, 2, 0))
			return (1);
	}
	else
	{
		if (ft_strstr(buffer, dec, 0, 0))
			return (1);
	}
	return (0);
}

int	check_index(char *buffer, int group)
{
	char	*dec;
	int		i;

	dec = (char *)malloc((group * 3) + 2);
	i = 0;
	dec[i] = '1';
	while (i <= group * 3)
	{
		i++;
		dec[i] = '0';
	}
	dec[i] = '\0';
	if (it_ok(buffer, dec))
		return (1);
	return (0);
}

int	traslate(char *buffer, char c, char d, int group)
{
	char	dec[3];

	dec[0] = c;
	if (c > '1')
		dec[1] = '0';
	else
		dec[1] = d;
	dec[2] = '\0';
	if (d == '0')
	{
		if (ft_strstr(buffer, dec, 2, group))
			return (1);
	}
	else
	{
		if (ft_strstr(buffer, dec, 1, group))
			return (1);
	}
	return (0);
}

int	print_nb(char **matrix, char *str, int group, char *buffer)
{
	if (check_index(buffer, group))
		return (1);
	if (str[0] != '0')
	{
		if (traslate(buffer, str[0], '\0', group))
			return (1);
		if (ft_strstr(buffer, "100", 0, group))
			return (1);
	}
	if (str[1] != '0')
	{
		if (traslate(buffer, str[1], str[2], group))
			return (1);
	}
	if (str[2] != '0' && str[1] != '1')
		if (ft_strstr(buffer, &str[2], 2, group))
			return (1);
	if (group != 0 && (str[0] != '0' || str[1] != '0' || str[2] != '0'))
		char_index(buffer, group, matrix);
	return (0);
}

void	proces_dict(char **matrix, int group, char *buffer)
{
	if (is_all_zero(matrix, group, buffer, 1))
	{
		while (group)
		{
			group--;
			if (print_nb(matrix, matrix[group], group, buffer))
				return ;
		}
	}
}
