/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:35:00 by luf-sanc          #+#    #+#             */
/*   Updated: 2025/07/20 12:27:38 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

#define NO_FLAG 1
#define SO_FLAG 2
#define WE_FLAG 4
#define EA_FLAG 8
#define F_FLAG 16
#define C_FLAG 32

static int	parse_line(char *line, t_game *game);
static void	parse_texture(char *line, char **path, int flag, t_game *game);
static void	parse_color(char *line, int *color, int flag, t_game *game);
static int	rgb_to_int(int r, int g, int b);

void	parse_scene_elements(int fd, t_game *game)
{
	char	*line;

	while (game->scene->elements_defined != (NO_FLAG | SO_FLAG | WE_FLAG | EA_FLAG | F_FLAG | C_FLAG))
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parse_line(line, game);
		free(line);
	}
}

static int	parse_line(char *line, t_game *game)
{
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "NO ", 3) == 0)
		parse_texture(line + 3, &game->scene->no_path, NO_FLAG, game);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		parse_texture(line + 3, &game->scene->so_path, SO_FLAG, game);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		parse_texture(line + 3, &game->scene->we_path, WE_FLAG, game);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		parse_texture(line + 3, &game->scene->ea_path, EA_FLAG, game);
	else if (ft_strncmp(line, "F ", 2) == 0)
		parse_color(line + 2, &game->scene->floor_color, F_FLAG, game);
	else if (ft_strncmp(line, "C ", 2) == 0)
		parse_color(line + 2, &game->scene->ceiling_color, C_FLAG, game);
	else if (*line == '#' || *line == '\n' || *line == '\0')
		return (0);
	else
		exit_error("Invalid identifier in scene file.", game);
	return (1);
}

static void	parse_texture(char *line, char **path, int flag, t_game *game)
{
	int	len;

	if (game->scene->elements_defined & flag)
		exit_error("Duplicate texture identifier.", game);
	while (*line == ' ')
		line++;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	*path = ft_strdup(line);
	if (!*path)
		exit_error("Memory allocation failed for texture path.", game);
	game->scene->elements_defined |= flag;
}

static void	parse_color(char *line, int *color, int flag, t_game *game)
{
	char	**rgb_values;
	int		r;
	int		g;
	int		b;

	if (game->scene->elements_defined & flag)
		exit_error("Duplicate color identifier.", game);
	rgb_values = ft_split(line, ',');
	if (!rgb_values || !rgb_values[0] || !rgb_values[1] || !rgb_values[2])
		exit_error("Invalid color format (must be R,G,B).", game);
	
	r = ft_atoi(rgb_values[0]);
	g = ft_atoi(rgb_values[1]);
	b = ft_atoi(rgb_values[2]);

	// TODO: Free rgb_values array
	
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_error("Color values must be between 0 and 255.", game);
	
	*color = rgb_to_int(r, g, b);
	game->scene->elements_defined |= flag;
}

static int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}