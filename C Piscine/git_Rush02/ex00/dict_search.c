/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:20:01 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/25 18:56:32 by carlosg2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "print_dict.h"

ssize_t	size_file(const char *file_name)
{
	int		fd;
	ssize_t	total_size;
	ssize_t	red_bytes;
	char	buffer[1];

	total_size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	red_bytes = read(fd, buffer, 1);
	while (red_bytes > 0)
	{
		total_size += red_bytes;
		red_bytes = read(fd, buffer, 1);
	}
	close(fd);
	if (red_bytes == -1)
		return (-1);
	return (total_size);
}

void	conv_dic(char **matrix, int group, char *dict)
{
	int		fd;
	ssize_t	size;
	char	*buffer;
	ssize_t	bytes_leidos;

	fd = open(dict, O_RDONLY);
	if (fd == -1)
		return ;
	size = size_file(dict);
	buffer = (char *)malloc(size + 1);
	if (buffer == NULL)
		return ;
	bytes_leidos = read(fd, buffer, size);
	if (bytes_leidos == -1)
	{
		close(fd);
		return ;
	}
	buffer[bytes_leidos] = '\0';
	proces_dict (matrix, group, buffer);
	free(buffer);
	close(fd);
}
