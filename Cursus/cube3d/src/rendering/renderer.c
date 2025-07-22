/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 21:25:00 by luf-sanc          #+#    #+#             */
/*   Updated: 2025/07/20 12:22:34 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_floor_ceiling(t_game *game, t_img *img);

/**
 * @brief Main rendering function, called on every frame.
 */
int	render_frame(t_game *game)
{
	t_img	img;

	img.img_ptr = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!img.img_ptr)
		exit_error("Failed to create image.", game);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_len, &img.endian);
	
	draw_floor_ceiling(game, &img);
	perform_raycasting(game, &img);
	
	mlx_put_image_to_window(game->mlx, game->win, img.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx, img.img_ptr);
	return (0);
}

/**
 * @brief Draws the floor and ceiling with solid colors.
 */
void	draw_floor_ceiling(t_game *game, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(img, x, y, game->scene->ceiling_color);
			x++;
		}
		y++;
	}
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(img, x, y, game->scene->floor_color);
			x++;
		}
		y++;
	}
}

/**
 * @brief Puts a pixel of a given color at a specified (x, y) coordinate.
 * This is a faster version of mlx_pixel_put.
 */
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}