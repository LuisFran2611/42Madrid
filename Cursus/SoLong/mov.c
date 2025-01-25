/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:01:45 by lsanchez          #+#    #+#             */
/*   Updated: 2025/01/25 11:01:03 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	the_end(t_game *game)
{
	free_resources(game);
	exit(0);
	return ;
}

void	move_up(t_game *game)
{
	if (game->map.grid[game->player.y - 1][game->player.x] == 'E'
		&& game->map.spc_char[0] != 0)
		return ;
	else if (game->map.grid[game->player.y - 1][game->player.x] == 'E'
		&& game->map.spc_char[0] == 0)
		the_end(game);
	else if (game->map.grid[game->player.y - 1][game->player.x] == '1')
		return ;
	else if (game->map.grid[game->player.y - 1][game->player.x] == 'C')
	{
		mlx_destroy_image(game->data.mlx_ptr, game->env.img_player.img_ptr);
		game->env.img_player.img_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
				"./img/like.xpm", &game->env.img_player.width,
				&game->env.img_player.height);
		game->map.spc_char[0]--;
		game->map.grid[game->player.y - 1][game->player.x] = 'P';
		game->map.grid[game->player.y][game->player.x] = '0';
		animate(game);
	}
	else if (game->map.grid[game->player.y - 1][game->player.x] == '0')
	{
		game->map.grid[game->player.y - 1][game->player.x] = 'P';
		game->map.grid[game->player.y][game->player.x] = '0';
	}
	game->player.moves++;
}

void	move_down(t_game *game)
{
	if (game->map.grid[game->player.y + 1][game->player.x] == 'E'
		&& game->map.spc_char[0] != 0)
		return ;
	else if (game->map.grid[game->player.y + 1][game->player.x] == 'E'
		&& game->map.spc_char[0] == 0)
		the_end(game);
	else if (game->map.grid[game->player.y + 1][game->player.x] == '1')
		return ;
	else if (game->map.grid[game->player.y + 1][game->player.x] == 'C')
	{
		mlx_destroy_image(game->data.mlx_ptr, game->env.img_player.img_ptr);
		game->env.img_player.img_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
				"./img/like.xpm", &game->env.img_player.width,
				&game->env.img_player.height);
		game->map.spc_char[0]--;
		game->map.grid[game->player.y + 1][game->player.x] = 'P';
		game->map.grid[game->player.y][game->player.x] = '0';
		animate(game);
	}
	else if (game->map.grid[game->player.y + 1][game->player.x] == '0')
	{
		game->map.grid[game->player.y + 1][game->player.x] = 'P';
		game->map.grid[game->player.y][game->player.x] = '0';
	}
	game->player.moves++;
}

void	move_left(t_game *game)
{
	if (game->map.grid[game->player.y][game->player.x - 1] == 'E'
		&& game->map.spc_char[0] != 0)
		return ;
	else if (game->map.grid[game->player.y][game->player.x - 1] == 'E'
		&& game->map.spc_char[0] == 0)
		the_end(game);
	else if (game->map.grid[game->player.y][game->player.x - 1] == '1')
		return ;
	else if (game->map.grid[game->player.y][game->player.x - 1] == 'C')
	{
		mlx_destroy_image(game->data.mlx_ptr, game->env.img_player.img_ptr);
		game->env.img_player.img_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
				"./img/like.xpm", &game->env.img_player.width,
				&game->env.img_player.height);
		game->map.spc_char[0]--;
		game->map.grid[game->player.y][game->player.x - 1] = 'P';
		game->map.grid[game->player.y][game->player.x] = '0';
		animate(game);
	}
	else if (game->map.grid[game->player.y][game->player.x - 1] == '0')
	{
		game->map.grid[game->player.y][game->player.x - 1] = 'P';
		game->map.grid[game->player.y][game->player.x] = '0';
	}
	game->player.moves++;
}

void	move_right(t_game *game)
{
	if (game->map.grid[game->player.y][game->player.x + 1] == 'E'
		&& game->map.spc_char[0] != 0)
		return ;
	else if (game->map.grid[game->player.y][game->player.x + 1] == 'E'
		&& game->map.spc_char[0] == 0)
		the_end(game);
	else if (game->map.grid[game->player.y][game->player.x + 1] == '1')
		return ;
	else if (game->map.grid[game->player.y][game->player.x + 1] == 'C')
	{
		mlx_destroy_image(game->data.mlx_ptr, game->env.img_player.img_ptr);
		game->env.img_player.img_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
				"./img/like.xpm", &game->env.img_player.width,
				&game->env.img_player.height);
		game->map.spc_char[0]--;
		game->map.grid[game->player.y][game->player.x + 1] = 'P';
		game->map.grid[game->player.y][game->player.x] = '0';
		animate(game);
	}
	else if (game->map.grid[game->player.y][game->player.x + 1] == '0')
	{
		game->map.grid[game->player.y][game->player.x + 1] = 'P';
		game->map.grid[game->player.y][game->player.x] = '0';
	}
	game->player.moves++;
}
