/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:17:14 by lsanchez          #+#    #+#             */
/*   Updated: 2025/01/25 10:06:10 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft.h"

char	**add_line_to_map(char **map, char *line, int *rows)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char *) * (*rows + 2));
	if (!tmp)
		return (NULL);
	while (i < *rows)
	{
		tmp[i] = map[i];
		i++;
	}
	tmp[i] = line;
	tmp[i + 1] = NULL;
	free(map);
	(*rows)++;
	return (tmp);
}

char	**read_file(char *file_path, int *rows)
{
	int		fd;
	char	**map;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = NULL;
	*rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		map = add_line_to_map(map, line, rows);
		if (!map)
		{
			free(line);
			free_char_matrix(map);
			close(fd);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
