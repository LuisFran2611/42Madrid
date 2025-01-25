/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:08:11 by lsanchez          #+#    #+#             */
/*   Updated: 2025/01/25 11:14:40 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_up(t_game *game)
{
	mlx_destroy_image(game->data.mlx_ptr, game->env.img_player.img_ptr);
	game->env.img_player.img_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"./img/issac_espalda.xpm", &game->env.img_player.width,
			&game->env.img_player.height);
}

void	img_down(t_game *game)
{
	mlx_destroy_image(game->data.mlx_ptr, game->env.img_player.img_ptr);
	game->env.img_player.img_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"./img/issac_frente.xpm", &game->env.img_player.width,
			&game->env.img_player.height);
}

void	img_left(t_game *game)
{
	mlx_destroy_image(game->data.mlx_ptr, game->env.img_player.img_ptr);
	game->env.img_player.img_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"./img/issac_izquierda.xpm", &game->env.img_player.width,
			&game->env.img_player.height);
}

void	img_right(t_game *game)
{
	mlx_destroy_image(game->data.mlx_ptr, game->env.img_player.img_ptr);
	game->env.img_player.img_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"./img/issac_derecha.xpm", &game->env.img_player.width,
			&game->env.img_player.height);
}
