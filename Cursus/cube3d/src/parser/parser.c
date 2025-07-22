/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:30:00 by luf-sanc          #+#    #+#             */
/*   Updated: 2025/07/20 12:34:36 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_parser_structs(t_game *game);
void		parse_scene_elements(int fd, t_game *game);
void		parse_map(int fd, t_game *game);

/**
 * @brief Main parsing function. Opens the file and orchestrates the parsing.
 * @param file_path Path to the .cub file.
 * @param game The main game structure.
 */
void	parse_file(char *file_path, t_game *game)
{
	int	fd;

	init_parser_structs(game);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		exit_error("Could not open file.", game);
	parse_scene_elements(fd, game);
	if (game->scene->elements_defined != 63) // 63 is the sum of all flags
		exit_error("Missing scene elements (NO, SO, WE, EA, F, C).", game);
	parse_map(fd, game);
	close(fd);
}

/**
 * @brief Initializes the structures needed for parsing.
 * @param game The main game structure.
 */
static void	init_parser_structs(t_game *game)
{
	game->scene = ft_calloc(1, sizeof(t_scene));
	if (!game->scene)
		exit_error("Memory allocation failed for scene.", NULL);
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
		exit_error("Memory allocation failed for map.", game);
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
		exit_error("Memory allocation failed for player.", game);
}