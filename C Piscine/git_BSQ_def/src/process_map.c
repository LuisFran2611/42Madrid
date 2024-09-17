/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:27:22 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/27 13:31:31 by mmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_map.h"
#include "create_map.h"
#include "process_map.h"

ssize_t	ft_file_size(const char *file_name)
{
	int		fd;
	ssize_t	total_size;
	ssize_t	read_bytes;
	char	buffer[1];

	total_size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	read_bytes = read(fd, buffer, 1);
	while (read_bytes > 0)
	{
		total_size += read_bytes;
		read_bytes = read(fd, buffer, 1);
	}
	close(fd);
	if (read_bytes == -1)
		return (-1);
	return (total_size);
}

void	ft_process_map(char *file)
{
	int		fd;
	ssize_t	size;
	char	*buffer;
	ssize_t	bytes_leidos;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	size = ft_file_size(file);
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
	ft_create_map(buffer);
	free(buffer);
	close(fd);
}
