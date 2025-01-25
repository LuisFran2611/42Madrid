/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:03:35 by lsanchez          #+#    #+#             */
/*   Updated: 2024/11/04 10:07:20 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_before_newline(const char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	res = ft_calloc(i + 1, sizeof (*res));
	if (!res)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

char	*get_after_newline(const char *s)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	while (s && s[j])
		j++;
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	res = ft_calloc((j - i) + 1, sizeof (*res));
	if (!res)
		return (0);
	j = 0;
	while (s[i + j])
	{
		res[j] = s[i + j];
		j++;
	}
	return (res);
}

void	ft_read_line(int fd, char **keep, char **tmp)
{
	char	*buf;
	int		r;

	buf = malloc(sizeof (*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			ft_free_strs(&buf, keep, tmp);
			return ;
		}
		buf[r] = '\0';
		*tmp = ft_strdup(*keep);
		ft_free_strs(keep, 0, 0);
		*keep = ft_strjoin(*tmp, buf);
		ft_free_strs(tmp, 0, 0);
		if (contains_newline(*keep))
			break ;
	}
	ft_free_strs(&buf, 0, 0);
}

char	*ft_parse_line(char **keep, char **tmp)
{
	char	*line;

	*tmp = ft_strdup(*keep);
	ft_free_strs(keep, 0, 0);
	*keep = get_after_newline(*tmp);
	line = get_before_newline(*tmp);
	ft_free_strs(tmp, 0, 0);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*keep[1024];
	char		*tmp;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (0);
	line = NULL;
	tmp = NULL;
	ft_read_line(fd, &keep[fd], &tmp);
	if (keep[fd] != NULL && *keep[fd])
		line = ft_parse_line(&keep[fd], &tmp);
	if (!line || *line == '\0')
	{
		ft_free_strs(&keep[fd], &line, &tmp);
		return (0);
	}
	return (line);
}