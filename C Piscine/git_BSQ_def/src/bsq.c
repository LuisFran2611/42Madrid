/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:11:51 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/27 20:30:33 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_map.h"
#include "struct_map.h"
#include "create_map.h"
#include "bsq.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFFER_SIZE 4096

char	*ft_read_buffer(char *buffer, int *lines_to_read)
{
	int		i;
	char	*input;

	i = 0;
	while (i < BUFFER_SIZE && buffer[i] != '\n')
		i++;
	if (i == BUFFER_SIZE)
		return (NULL);
	buffer[i] = '\0';
	*lines_to_read = atoi(buffer) + 1;
	input = malloc(BUFFER_SIZE + 1);
	if (!input)
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		input[i] = buffer[i];
		i++;
	}
	input[BUFFER_SIZE] = '\0';
	return (input);
}

char	*ft_realloc_input(char *input, int tot_size, char *buffer, int r_size)
{
	char	*temp;
	int		i;

	temp = malloc(tot_size + r_size + 1);
	if (!temp)
	{
		free(input);
		return (NULL);
	}
	i = 0;
	while (i < tot_size)
	{
		temp[i] = input[i];
		i++;
	}
	free(input);
	i = 0;
	while (i < r_size)
	{
		temp[tot_size + i] = buffer[i];
		i++;
	}
	temp[tot_size + r_size] = '\0';
	return (temp);
}

int	ft_count_lines(char *buffer, int read_size)
{
	int	lines;
	int	i;

	lines = 0;
	i = 0;
	while (i < read_size)
	{
		if (buffer[i] == '\n')
			lines++;
		i++;
	}
	return (lines);
}

void	ft_process_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		write(2, "map error\n", 10);
	else
	{
		ft_process_map(filename);
		if (close(fd) == -1)
			write(2, "map error\n", 10);
		write(1, "\n", 1);
	}
}

int	main(int ac, char **av)
{
	char	*stdin_input;
	int		i;

	if (ac == 1)
	{
		stdin_input = ft_read_stdin();
		if (stdin_input)
		{	
			ft_create_map(stdin_input);
			free(stdin_input);
		}
		else
			write(2, "map error\n", 10);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			ft_process_file(av[i]);
			i++;
		}
	}
	return (0);
}
