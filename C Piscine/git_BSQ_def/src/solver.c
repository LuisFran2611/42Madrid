/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedrano <mmedrano@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:02:23 by mmedrano          #+#    #+#             */
/*   Updated: 2024/08/27 13:40:46 by mmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "struct_map.h"
#include "struct_square.h"

void	ft_print_map(t_map *map, int size, int l_size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, map->map[i], l_size);
		write(1, "\n", 1);
		i++;
	}
}

int	ft_check_sol(t_map *map, t_square *sol)
{
	int	i;
	int	j;

	i = 0;
	while (i < sol->size)
	{
		j = 0;
		while (j < sol->size)
		{
			if (map->map[sol->x + i][sol->y + j] != map->chars[0])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_put_sol(t_map *map, t_square *sol)
{
	int	i;
	int	j;

	i = 0;
	while (i < sol->size)
	{
		j = 0;
		while (j < sol->size)
		{
			map->map[sol->x + i][sol->y + j] = map->chars[2];
			j++;
		}
		i++;
	}
}

int	ft_solve_helper(t_map *map, int size, int l_size, int max_size)
{
	int			i;
	int			j;
	t_square	sol;

	i = 0;
	while ((i + max_size) <= l_size)
	{
		j = 0;
		while ((j + max_size) <= size)
		{
			sol.x = i;
			sol.y = j;
			sol.size = max_size;
			if (ft_check_sol(map, &sol))
			{
				ft_put_sol(map, &sol);
				ft_print_map(map, size, l_size);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_solve(t_map *map, int size, int l_size)
{
	int	max_size;

	if (size > l_size)
		max_size = l_size;
	else
		max_size = size;
	while (max_size)
	{
		if (ft_solve_helper(map, size, l_size, max_size))
			return ;
		max_size--;
	}
}
