/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 21:15:00 by luf-sanc          #+#    #+#             */
/*   Updated: 2025/07/20 12:15:21 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Handles the event of closing the window via the red cross.
 */
int	close_window_hook(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}

/**
 * @brief Handles key press events.
 */
int	key_press_hook(int keycode, t_game *game)
{
	if (keycode == K_ESC)
	{
		cleanup(game);
		exit(0);
	}
	if (keycode == K_W || keycode == K_S)
		move_player(keycode, game);
	if (keycode == K_LEFT || keycode == K_RIGHT)
		rotate_player(keycode, game);
	return (0);
}