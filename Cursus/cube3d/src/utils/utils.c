/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:40:00 by luf-sanc          #+#    #+#             */
/*   Updated: 2025/07/21 10:28:57 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	free_map_grid(char **grid, int height)
{
	int	i;

	i = 0;
	if (!grid)
		return ;
	while (i < height && grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

/**
 * @brief Frees all allocated memory.
 *
 * @param game The main game structure.
 */
void	cleanup(t_game *game)
{
	if (!game)
		return ;
	if (game->scene)
	{
		if (game->scene->no_path)
			free(game->scene->no_path);
		if (game->scene->so_path)
			free(game->scene->so_path);
		if (game->scene->we_path)
			free(game->scene->we_path);
		if (game->scene->ea_path)
			free(game->scene->ea_path);
		free(game->scene);
	}
	if (game->map)
	{
		if (game->map->grid)
			free_map_grid(game->map->grid, game->map->height);
		free(game->map);
	}
	free(game->player);
}

/**
 * @brief Prints an error message and exits the program after cleaning up.
 *
 * @param message The error message to display.
 * @param game The main game structure for cleanup.
 */
void	exit_error(char *message, t_game *game)
{
	int	i;

	write(2, "Error\n", 6);
	if (message)
	{
		i = 0;
		while (message[i])
			i++;
		write(2, message, i);
		write(2, "\n", 1);
	}
	cleanup(game);
	exit(1);
}