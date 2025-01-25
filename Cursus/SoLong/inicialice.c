/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:51:26 by lsanchez          #+#    #+#             */
/*   Updated: 2025/01/25 11:03:28 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	inicialice_player(t_game *game)
{
	game->player.x = 0;
	game->player.y = 0;
	game->player.moves = 0;
}

void	inicilice_map(t_game *game)
{
	game->map.spc_char[0] = 0;
	game->map.spc_char[1] = 0;
	game->map.spc_char[2] = 0;
	game->map.height = 0;
	game->map.grid = read_file(game->data.path, &game->map.height);
	if (game->map.grid == NULL)
		return ;
	game->map.width = ft_strlen(game->map.grid[0]) - 1;
	game->data.win_width = game->map.width * TILE_SIZE;
	game->data.win_height = game->map.height * TILE_SIZE;
}

void	inicialice_env(t_game *game)
{
	game->env.img_wall.img_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"./img/pop.xpm", &game->env.img_wall.width,
			&game->env.img_wall.height);
	game->env.img_floor.img_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"./img/floor.xpm", &game->env.img_floor.width,
			&game->env.img_floor.height);
	game->env.img_player.img_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"./img/issac_frente.xpm", &game->env.img_player.width,
			&game->env.img_player.height);
	game->env.img_col.img_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"./img/dado.xpm", &game->env.img_col.width,
			&game->env.img_col.height);
	game->env.img_exit.img_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"./img/exit.xpm", &game->env.img_exit.width,
			&game->env.img_exit.height);
}

void	calc_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'C')
				game->map.spc_char[0]++;
			else if (game->map.grid[y][x] == 'P')
			{
				game->map.spc_char[1]++;
				game->player.x = x;
				game->player.y = y;
			}
			else if (game->map.grid[y][x] == 'E')
				game->map.spc_char[2]++;
			x++;
		}
		y++;
	}
}

int	inicialice(t_game *game)
{
	game->data.mlx_ptr = mlx_init();
	if (!game->data.mlx_ptr)
		return (1);
	inicialice_env(game);
	inicilice_map(game);
	inicialice_player(game);
	calc_map(game);
	if (check_map(game))
		return (1);
	game->data.win_ptr = mlx_new_window(game->data.mlx_ptr,
			game->data.win_width, game->data.win_height, "./So_Long");
	if (!game->data.win_ptr)
		return (1);
	draw_map(game);
	return (0);
}
