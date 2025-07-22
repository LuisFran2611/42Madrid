/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:10:00 by luf-sanc          #+#    #+#             */
/*   Updated: 2025/07/21 11:05:19 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_player_direction(t_player *player, char direction);
static void	find_player_start(t_game *game);
static void	load_textures(t_game *game);

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error("Failed to initialize mlx.", game);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!game->win)
		exit_error("Failed to create window.", game);
	find_player_start(game);
	load_textures(game);
}

static void	load_textures(t_game *game)
{
	game->scene->no_tex.img_ptr = mlx_xpm_file_to_image(game->mlx, game->scene->no_path, &game->scene->no_tex.width, &game->scene->no_tex.height);
	game->scene->so_tex.img_ptr = mlx_xpm_file_to_image(game->mlx, game->scene->so_path, &game->scene->so_tex.width, &game->scene->so_tex.height);
	game->scene->we_tex.img_ptr = mlx_xpm_file_to_image(game->mlx, game->scene->we_path, &game->scene->we_tex.width, &game->scene->we_tex.height);
	game->scene->ea_tex.img_ptr = mlx_xpm_file_to_image(game->mlx, game->scene->ea_path, &game->scene->ea_tex.width, &game->scene->ea_tex.height);
	if (!game->scene->no_tex.img_ptr || !game->scene->so_tex.img_ptr || \
		!game->scene->we_tex.img_ptr || !game->scene->ea_tex.img_ptr)
		exit_error("Failed to load textures.", game);
	game->scene->no_tex.addr = mlx_get_data_addr(game->scene->no_tex.img_ptr, &game->scene->no_tex.bpp, &game->scene->no_tex.line_len, &game->scene->no_tex.endian);
	game->scene->so_tex.addr = mlx_get_data_addr(game->scene->so_tex.img_ptr, &game->scene->so_tex.bpp, &game->scene->so_tex.line_len, &game->scene->so_tex.endian);
	game->scene->we_tex.addr = mlx_get_data_addr(game->scene->we_tex.img_ptr, &game->scene->we_tex.bpp, &game->scene->we_tex.line_len, &game->scene->we_tex.endian);
	game->scene->ea_tex.addr = mlx_get_data_addr(game->scene->ea_tex.img_ptr, &game->scene->ea_tex.bpp, &game->scene->ea_tex.line_len, &game->scene->ea_tex.endian);
	printf("DEBUG: NO_TEX addr=%p\n", game->scene->no_tex.addr);
	printf("DEBUG: SO_TEX addr=%p\n", game->scene->so_tex.addr);
	printf("DEBUG: WE_TEX addr=%p\n", game->scene->we_tex.addr);
	printf("DEBUG: EA_TEX addr=%p\n", game->scene->ea_tex.addr);
}

static void	find_player_start(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (game->map->grid[y][x])
		{
			if (ft_strchr("NSEW", game->map->grid[y][x]))
			{
				game->player->pos_x = x + 0.5;
				game->player->pos_y = y + 0.5;
				init_player_direction(game->player, game->map->grid[y][x]);
				game->map->grid[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	init_player_direction(t_player *player, char direction)
{
	if (direction == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (direction == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (direction == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (direction == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
}