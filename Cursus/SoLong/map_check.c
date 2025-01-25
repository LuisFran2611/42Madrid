/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:51:10 by lsanchez          #+#    #+#             */
/*   Updated: 2025/01/25 11:21:41 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(t_game *game)
{
	int	i;

	if (game->map.width == game->map.height)
		return (0);
	i = 0;
	while (i < game->map.height)
	{
		if (ft_strlen(game->map.grid[i]) - 1 != game->map.width)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_closed(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map.width)
	{
		if (game->map.grid[0][x] != '1' || game->map.grid[game->map.height
			- 1][x] != '1')
			return (0);
		x++;
	}
	while (x < game->map.height)
	{
		if (game->map.grid[x][0] != '1' || game->map.grid[x][game->map.width
			- 1] != '1')
			return (0);
		x++;
	}
	return (1);
}

void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height
		|| map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'V';
		return ;
	}
	if (map[y][x] == '0' || map[y][x] == 'C')
		map[y][x] = 'V';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

int	is_valid_map(t_game *game)
{
	int		y[2];
	char	**map_copy;

	map_copy = copy_file(game->map.grid, game->map.height);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->player.x, game->player.y, game);
	y[0] = 0;
	while (y[0] < game->map.height)
	{
		y[1] = 0;
		while (y[1] < game->map.width)
		{
			if (game->map.grid[y[0]][y[1]] == 'C'
				|| game->map.grid[y[0]][y[1]] == 'E')
				if (!is_valid(map_copy, y))
					return (0);
			y[1]++;
		}
		y[0]++;
	}
	free_char_matrix(map_copy);
	return (1);
}

int	check_map(t_game *game)
{
	if (game->map.grid == NULL)
	{
		ft_printf("Error\nMapa Nulo\n");
		return (1);
	}
	if (game->map.spc_char[1] != 1 || game->map.spc_char[2] != 1)
	{
		ft_printf("Error\nFalta la salida o el jugador\n");
		return (1);
	}
	if (game->map.spc_char[0] < 1)
	{
		ft_printf("Error\nFalta almenos un colecionable\n");
		return (1);
	}
	if (!is_rectangular(game) || !is_valid_map(game) || !is_closed(game))
	{
		ft_printf("Error\nEl mapa no cumple las normas de mapa valido\n");
		return (1);
	}
	return (0);
}
