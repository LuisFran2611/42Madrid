/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 21:30:00 by luf-sanc          #+#    #+#             */
/*   Updated: 2025/07/21 10:59:57 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}	t_ray;

void	perform_raycasting(t_game *game, t_img *img)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		ray.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		ray.ray_dir_x = game->player->dir_x + game->player->plane_x * ray.camera_x;
		ray.ray_dir_y = game->player->dir_y + game->player->plane_y * ray.camera_x;
		ray.map_x = (int)game->player->pos_x;
		ray.map_y = (int)game->player->pos_y;
		ray.delta_dist_x = fabs(1 / ray.ray_dir_x);
		ray.delta_dist_y = fabs(1 / ray.ray_dir_y);
		if (ray.ray_dir_x < 0)
		{
			ray.step_x = -1;
			ray.side_dist_x = (game->player->pos_x - ray.map_x) * ray.delta_dist_x;
		}
		else
		{
			ray.step_x = 1;
			ray.side_dist_x = (ray.map_x + 1.0 - game->player->pos_x) * ray.delta_dist_x;
		}
		if (ray.ray_dir_y < 0)
		{
			ray.step_y = -1;
			ray.side_dist_y = (game->player->pos_y - ray.map_y) * ray.delta_dist_y;
		}
		else
		{
			ray.step_y = 1;
			ray.side_dist_y = (ray.map_y + 1.0 - game->player->pos_y) * ray.delta_dist_y;
		}
		ray.hit = 0;
		while (ray.hit == 0)
		{
			if (ray.side_dist_x < ray.side_dist_y)
			{
				ray.side_dist_x += ray.delta_dist_x;
				ray.map_x += ray.step_x;
				ray.side = 0;
			}
			else
			{
				ray.side_dist_y += ray.delta_dist_y;
				ray.map_y += ray.step_y;
				ray.side = 1;
			}
			if (game->map->grid[ray.map_y][ray.map_x] == '1')
				ray.hit = 1;
		}
		if (ray.side == 0)
			ray.perp_wall_dist = (ray.map_x - game->player->pos_x + (1 - ray.step_x) / 2) / ray.ray_dir_x;
		else
			ray.perp_wall_dist = (ray.map_y - game->player->pos_y + (1 - ray.step_y) / 2) / ray.ray_dir_y;
		ray.line_height = (int)(SCREEN_HEIGHT / ray.perp_wall_dist);
		ray.draw_start = -ray.line_height / 2 + SCREEN_HEIGHT / 2;
		if (ray.draw_start < 0)
			ray.draw_start = 0;
		ray.draw_end = ray.line_height / 2 + SCREEN_HEIGHT / 2;
		if (ray.draw_end >= SCREEN_HEIGHT)
			ray.draw_end = SCREEN_HEIGHT - 1;
		
		t_img *texture = &game->scene->no_tex;
		if (ray.side == 0)
		{
			if (ray.ray_dir_x > 0)
				texture = &game->scene->ea_tex;
			else
				texture = &game->scene->we_tex;
		}
		else
		{
			if (ray.ray_dir_y > 0)
				texture = &game->scene->so_tex;
		}

		if (ray.side == 0)
			ray.wall_x = game->player->pos_y + ray.perp_wall_dist * ray.ray_dir_y;
		else
			ray.wall_x = game->player->pos_x + ray.perp_wall_dist * ray.ray_dir_x;
		ray.wall_x -= floor(ray.wall_x);
		
		ray.tex_x = (int)(ray.wall_x * (double)texture->width);
		if (ray.side == 0 && ray.ray_dir_x > 0)
			ray.tex_x = texture->width - ray.tex_x - 1;
		if (ray.side == 1 && ray.ray_dir_y < 0)
			ray.tex_x = texture->width - ray.tex_x - 1;
			
		ray.step = 1.0 * texture->height / ray.line_height;
		ray.tex_pos = (ray.draw_start - SCREEN_HEIGHT / 2 + ray.line_height / 2) * ray.step;
		
		int y = ray.draw_start;
		while (y < ray.draw_end)
		{
			ray.tex_y = (int)ray.tex_pos & (texture->height - 1);
			ray.tex_pos += ray.step;
			int color = *(unsigned int*)(texture->addr + (ray.tex_y * texture->line_len + ray.tex_x * (texture->bpp / 8)));
			my_mlx_pixel_put(img, x, y, color);
			y++;
		}
		x++;
	}
}