/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:29:45 by lsanchez          #+#    #+#             */
/*   Updated: 2025/01/25 11:33:29 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate(t_game *game)
{
	int	i;

	i = 0;
	while (i < T_ANIMACION)
	{
		draw_map(game);
		i++;
	}
}

void	print_img(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
		game->env.img_floor.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	if (game->map.grid[y][x] == '1')
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->env.img_wall.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map.grid[y][x] == 'C')
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->env.img_col.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map.grid[y][x] == 'P')
	{
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->env.img_player.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
		game->player.x = x;
		game->player.y = y;
	}
	else if (game->map.grid[y][x] == 'E')
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->env.img_exit.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
}

void	draw_map(t_game *game)
{
	char	*moves_str;
	int		x;
	int		y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			print_img(game, x, y);
			x++;
		}
		y++;
	}
	moves_str = ft_itoa(game->player.moves);
	if (!moves_str)
		return ;
	mlx_string_put(game->data.mlx_ptr, game->data.win_ptr, 10, 10, 0xFFFFFF,
		"Movimientos:");
	mlx_string_put(game->data.mlx_ptr, game->data.win_ptr, 120, 10, 0xFFFFFF,
		moves_str);
	free(moves_str);
}

void	gen_move(int keycode, t_game *game)
{
	if (ft_isup(keycode) && game->map.grid
		[game->player.y - 1][game->player.x] != '1')
	{
		move_up(game);
		img_up(game);
	}
	if (ft_isdown(keycode))
	{
		move_down(game);
		img_down(game);
	}
	if (ft_isleft(keycode) && game->map.grid[game->player.y][game->player.x
		- 1] != '1')
	{
		move_left(game);
		img_left(game);
	}
	if (ft_isright(keycode) && game->map.grid[game->player.y][game->player.x
		+ 1] != '1')
	{
		move_right(game);
		img_right(game);
	}
	draw_map(game);
}
