/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:45:00 by luf-sanc          #+#    #+#             */
/*   Updated: 2025/07/19 19:06:12 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// Forward declarations
static t_list	*read_map_lines(int fd, t_game *game);
static void		convert_list_to_grid(t_list *map_list, t_game *game);
static void		validate_map_content(t_game *game);

/**
 * @brief Reads the map from the file, validates it, and stores it.
 */
void	parse_map(int fd, t_game *game)
{
	t_list	*map_list;

	map_list = read_map_lines(fd, game);
	if (!map_list)
		exit_error("Map not found or empty.", game);
	convert_list_to_grid(map_list, game);
	ft_lstclear(&map_list, free); // Assumes ft_lstclear from libft
	validate_map_content(game);
	// TODO: Add flood_fill validation for closed map
}

/**
 * @brief Reads map lines from the file descriptor into a linked list.
 */
static t_list	*read_map_lines(int fd, t_game *game)
{
	t_list	*map_list;
	char	*line;
	int		map_started;

	map_list = NULL;
	map_started = 0;
	while ((line = get_next_line(fd))) // Assumes get_next_line
	{
		if (*line == '\n' && !map_started)
		{
			free(line);
			continue ;
		}
		if (*line != '\n' && *line != '\0')
		{
			map_started = 1;
			ft_lstadd_back(&map_list, ft_lstnew(line)); // Assumes libft
		}
		else if (map_started)
			exit_error("Empty line inside map.", game);
	}
	return (map_list);
}

/**
 * @brief Converts the linked list of map lines into a char** grid.
 */
static void	convert_list_to_grid(t_list *map_list, t_game *game)
{
	int		i;
	int		size;
	t_list	*current;

	size = ft_lstsize(map_list); // Assumes ft_lstsize
	game->map->height = size;
	game->map->grid = ft_calloc(size + 1, sizeof(char *));
	if (!game->map->grid)
		exit_error("Memory allocation failed for map grid.", game);
	i = 0;
	current = map_list;
	while (current)
	{
		game->map->grid[i] = ft_strtrim((char *)current->content, "\n");
		if (!game->map->grid[i])
			exit_error("Memory allocation failed during map trim.", game);
		current->content = NULL; // Avoid double free
		i++;
		current = current->next;
	}
}

/**
 * @brief Validates the characters and player count in the map.
 */
static void	validate_map_content(t_game *game)
{
	int	x;
	int	y;
	int	player_found;

	y = 0;
	player_found = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (game->map->grid[y][x])
		{
			if (ft_strchr(" 01NSEW", game->map->grid[y][x]) == NULL)
				exit_error("Invalid character in map.", game);
			if (ft_strchr("NSEW", game->map->grid[y][x]))
			{
				if (player_found)
					exit_error("Multiple players found in map.", game);
				player_found = 1;
				// TODO: Store player start position and orientation
			}
			x++;
		}
		y++;
	}
	if (!player_found)
		exit_error("No player found in map.", game);
}