/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedrano <mmedrano@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:47:51 by mmedrano          #+#    #+#             */
/*   Updated: 2024/08/27 20:09:14 by mmedrano         ###   ########.fr       */
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

char	*ft_read_stdin(void)
{
	char	buffer[BUFFER_SIZE];
	char	*input;
	int		sizes[2];
	int		lines[2];

	sizes[1] = read(0, buffer, BUFFER_SIZE);
	if (sizes[1] <= 0)
		return (NULL);
	input = ft_read_buffer(buffer, &lines[0]);
	if (!input)
		return (NULL);
	sizes[0] = sizes[1];
	lines[1] = 1;
	while (lines[1] < lines[0])
	{
		sizes[1] = read(0, buffer, BUFFER_SIZE);
		if (sizes[1] <= 0)
			break ;
		input = ft_realloc_input(input, sizes[0], buffer, sizes[1]);
		if (!input)
			return (NULL);
		sizes[0] += sizes[1];
		lines[1] += ft_count_lines(buffer, sizes[1]);
	}
	return (input);
}
