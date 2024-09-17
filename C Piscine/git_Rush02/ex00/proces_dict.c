/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proces_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:01:55 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/25 22:05:18 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "dict_search.h"
#include "print_dict.h"
#include "ft_strcmp.h"

void	ft_putstr(char *str, int ind, int group)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ' || (*str >= '\t' && *str <= '\r'))
		i++;
	if (str[i] == ':')
		i++;
	while (str[i] == ' ' || (*str >= '\t' && *str <= '\r'))
		i++;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		i++;
	}
	if (ind == 2 && group == 0)
		write(1, "\n", 1);
	else
		write(1, " ", 1);
}

int	is_negative(char *str, char *to_find, int ind, int group)
{
	char	c;

	c = ft_strcmp(str, to_find);
	str--;
	if (*str != '-')
	{
		if (c == ' ' || (c >= '\t' && c <= '\r') || c == ':')
		{
			str++;
			ft_putstr(str, ind, group);
			return (0);
		}
	}
	return (1);
}

int	ft_strstr(char *str, char *to_find, int ind, int group)
{
	char	*c1;
	char	*c2;

	while (*str)
	{
		c1 = str;
		c2 = to_find;
		while (*c1 && *c2 && (*c1 == *c2))
		{
			c1++;
			c2++;
		}
		if (*c2 == '\0' && !is_negative(str, to_find, ind, group))
		{
			return (0);
		}
		else
			c2 = to_find;
		str++;
	}
	write(1, "Dict Error\n", 11);
	return (1);
}

int	it_ok(char *str, char *to_find)
{
	char	*c1;
	char	*c2;

	while (*str)
	{
		c1 = str;
		c2 = to_find;
		while (*c1 && *c2 && (*c1 == *c2))
		{
			c1++;
			c2++;
		}
		if (*c2 == '\0')
		{
			return (0);
		}
		str++;
	}
	write(1, "Dict Error\n", 11);
	return (1);
}

int	is_all_zero(char **matrix, int group, char *buffer, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (i < group)
	{
		j = 0;
		while (j < 3)
		{
			if (matrix[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	if (flag)
		ft_strstr(buffer, "0", 2, 0);
	return (0);
}
