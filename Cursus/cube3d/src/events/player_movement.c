/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:15:00 by luf-sanc          #+#    #+#             */
/*   Updated: 2025/07/20 12:13:33 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// Define movement and rotation speeds
#define MOVE_SPEED 0.1
#define ROT_SPEED 0.05

void	move_player(int keycode, t_game *game)
{
	if (keycode == K_W)
	{
		if (game->map->grid[(int)(game->player->pos_y)][(int)(game->player->pos_x + game->player->dir_x * MOVE_SPEED)] != '1')
			game->player->pos_x += game->player->dir_x * MOVE_SPEED;
		if (game->map->grid[(int)(game->player->pos_y + game->player->dir_y * MOVE_SPEED)][(int)(game->player->pos_x)] != '1')
			game->player->pos_y += game->player->dir_y * MOVE_SPEED;
	}
	if (keycode == K_S)
	{
		if (game->map->grid[(int)(game->player->pos_y)][(int)(game->player->pos_x - game->player->dir_x * MOVE_SPEED)] != '1')
			game->player->pos_x -= game->player->dir_x * MOVE_SPEED;
		if (game->map->grid[(int)(game->player->pos_y - game->player->dir_y * MOVE_SPEED)][(int)(game->player->pos_x)] != '1')
			game->player->pos_y -= game->player->dir_y * MOVE_SPEED;
	}
	// Strafe movement (A/D) can be added here
}

void	rotate_player(int keycode, t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	if (keycode == K_RIGHT)
	{
		old_dir_x = game->player->dir_x;
		game->player->dir_x = game->player->dir_x * cos(-ROT_SPEED) - game->player->dir_y * sin(-ROT_SPEED);
		game->player->dir_y = old_dir_x * sin(-ROT_SPEED) + game->player->dir_y * cos(-ROT_SPEED);
		old_plane_x = game->player->plane_x;
		game->player->plane_x = game->player->plane_x * cos(-ROT_SPEED) - game->player->plane_y * sin(-ROT_SPEED);
		game->player->plane_y = old_plane_x * sin(-ROT_SPEED) + game->player->plane_y * cos(-ROT_SPEED);
	}
	if (keycode == K_LEFT)
	{
		old_dir_x = game->player->dir_x;
		game->player->dir_x = game->player->dir_x * cos(ROT_SPEED) - game->player->dir_y * sin(ROT_SPEED);
		game->player->dir_y = old_dir_x * sin(ROT_SPEED) + game->player->dir_y * cos(ROT_SPEED);
		old_plane_x = game->player->plane_x;
		game->player->plane_x = game->player->plane_x * cos(ROT_SPEED) - game->player->plane_y * sin(ROT_SPEED);
		game->player->plane_y = old_plane_x * sin(ROT_SPEED) + game->player->plane_y * cos(ROT_SPEED);
	}
}