/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedrano <mmedrano@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:27:42 by mmedrano          #+#    #+#             */
/*   Updated: 2024/08/27 20:36:10 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct_map.h"
#include <unistd.h>

int	ft_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int	ft_validate_chars(char *chars)
{
	if (chars[0] == chars[1] || chars[0] == chars[2]
		|| chars[1] == chars[2])
		return (0);
	if (!ft_is_printable(chars[0]) || !ft_is_printable(chars[1])
		|| !ft_is_printable(chars[2]))
		return (0);
	return (1);
}

int	ft_validate_map_line(char *map, char *chars, int size)
{
	int	cont;

	cont = 0;
	while (*map != '\n' && *map)
	{
		if (!(*map == chars[0] || *map == chars[1] || *map == chars[2]))
			return (0);
		cont++;
		map++;
	}
	if (cont != size && size != 0)
		return (0);
	if (*map == '\n')
		map++;
	if (*map == '\0')
		return (1);
	return (ft_validate_map_line(map, chars, cont));
}

int	ft_validate_map(char *buffer)
{
	int		j;
	char	chars[3];
	char	*next_line;

	next_line = buffer;
	while (*next_line >= '0' && *next_line <= '9')
		next_line++;
	j = 0;
	while (j < 3)
	{
		chars[j] = *next_line;
		j++;
		next_line++;
	}
	if (!(*next_line == '\n' || *next_line == '\0'))
		return (0);
	if (!ft_validate_chars(chars))
		return (0);
	next_line++;
	if (!ft_validate_map_line(next_line, chars, 0))
		return (0);
	return (1);
}
