/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedrano <mmedrano@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:48:17 by mmedrano          #+#    #+#             */
/*   Updated: 2024/08/27 13:30:57 by mmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct_map.h"

int	ft_map_mem(t_map *map, int size, int l_size)
{
	int	i;

	i = 0;
	map->map = (char **)malloc((size + 1) * sizeof(char *));
	if (!map->map)
		return (0);
	while (i < size)
	{
		map->map[i] = (char *)malloc((l_size + 1) * sizeof(char));
		if (!map->map[i])
		{
			while (i-- > 0)
				free(map->map[i]);
			free(map->map);
			return (0);
		}
		i++;
	}
	map->map[i] = (char *)malloc(sizeof(char));
	if (!map->map[i])
		return (0);
	map->map[i][0] = '\0';
	return (1);
}
