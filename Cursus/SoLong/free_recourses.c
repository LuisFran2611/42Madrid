/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_recourses.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:48:09 by lsanchez          #+#    #+#             */
/*   Updated: 2025/02/12 09:25:45 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_resources(t_game *game)
{
	if (game->env.img_wall.img_ptr)
		mlx_destroy_image(game->data.mlx_ptr, game->env.img_wall.img_ptr);
	if (game->env.img_floor.img_ptr)
		mlx_destroy_image(game->data.mlx_ptr, game->env.img_floor.img_ptr);
	if (game->env.img_player.img_ptr)
		mlx_destroy_image(game->data.mlx_ptr, game->env.img_player.img_ptr);
	if (game->env.img_exit.img_ptr)
		mlx_destroy_image(game->data.mlx_ptr, game->env.img_exit.img_ptr);
	if (game->env.img_col.img_ptr)
		mlx_destroy_image(game->data.mlx_ptr, game->env.img_col.img_ptr);
	if (game->data.win_ptr)
		mlx_destroy_window(game->data.mlx_ptr, game->data.win_ptr);
	if (game->map.grid)
		free_char_matrix(game->map.grid);
	if (game->data.mlx_ptr)
		mlx_destroy_display(game->data.mlx_ptr);
	if (game->data.mlx_ptr)
		free(game->data.mlx_ptr);
}

int	check_path(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	if (len < 5)
		return (0);
	if (str[len - 1] == 'r' && str[len - 2] == 'e' && str[len - 3] == 'b'
		&& str[len - 4] == '.' && str[len - 5] != '/')
		return (1);
	ft_printf("Error\nMapa no tiene el formaro .ber\n");
	return (0);
}

int	is_valid(char **map_copy, int y[2])
{
	if (map_copy[y[0]][y[1]] != 'V')
	{
		free_char_matrix(map_copy);
		return (0);
	}
	return (1);
}

int	is_object(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E');
}
