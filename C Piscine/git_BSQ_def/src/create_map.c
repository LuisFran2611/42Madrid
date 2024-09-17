/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:07:33 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/27 20:26:17 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "struct_map.h"
#include "solver.h"
#include "mem_allocation.h"
#include "validate_map.h"

char	*ft_parse_chars(t_map *map, char *buffer)
{
	int	i;

	i = 0;
	while (*buffer >= '0' && *buffer <= '9')
		buffer++;
	while (i < 3)
	{
		map->chars[i] = *buffer;
		i++;
		buffer++;
	}
	buffer++;
	return (buffer);
}

int	ft_col_count(char *buffer)
{
	int	count;

	count = 0;
	while (*buffer)
	{
		if (*buffer == '\n')
			count++;
		buffer++;
	}
	return (count);
}

int	ft_row_size(char *buffer)
{
	int	cont;

	cont = 0;
	while (*buffer != '\n' && *buffer != '\0')
	{
		cont++;
		buffer++;
	}
	return (cont);
}

void	ft_fill_map(char *buffer, t_map *map, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (*buffer != '\0' && *buffer != '\n')
		{
			map->map[i][j] = *buffer;
			buffer++;
			j++;
		}
		map->map[i][j] = '\0';
		if (*buffer == '\n')
			buffer++;
		i++;
	}
}

void	ft_create_map(char *buffer)
{
	t_map	map;
	int		size;
	int		l_size;

	if (!ft_validate_map(buffer))
	{
		write(2, "map error\n", 10);
		return ;
	}
	buffer = ft_parse_chars(&map, buffer);
	size = ft_col_count(buffer);
	l_size = ft_row_size(buffer);
	if (ft_map_mem(&map, size, l_size))
	{
		ft_fill_map(buffer, &map, size);
		ft_solve(&map, size, l_size);
	}
	else
		write(2, "map error\n", 10);
}
