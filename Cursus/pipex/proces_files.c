/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proces_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:13:51 by lsanchez          #+#    #+#             */
/*   Updated: 2025/01/26 19:58:40 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_files(t_pipex *pipex)
{
	pipex->files.inf_fd = open(pipex->files.inf, O_RDONLY);
	if (pipex->files.inf_fd == -1)
	{
		perror("Error: No se puede acceder a infile");
		exit(EXIT_FAILURE);
	}
	pipex->files.outf_fd = open(pipex->files.outf, O_WRONLY | O_CREAT | O_TRUNC,
			0644);
	if (pipex->files.outf_fd == -1)
	{
		perror("Error: No se puede crear o escribir en outfile");
		close(pipex->files.inf_fd);
		exit(EXIT_FAILURE);
	}
}

char	*cat(char *str1, char *str2)
{
	int		len1;
	int		len2;
	char	*result;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	result = (char *)malloc(len1 + len2 + 2);
	if (!result)
		return (NULL);
	ft_strcpy(result, str1);
	result[len1] = '/';
	free(str1);
	ft_strcpy(result + len1 + 1, str2);
	result[len1 + len2 + 1] = '\0';
	return (result);
}

char	*get_path(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->proc.envp[i])
	{
		if (ft_strncmp(pipex->proc.envp[i], "PATH=", 5) == 0)
			return (pipex->proc.envp[i] + 5);
		i++;
	}
	return (NULL);
}

void	proces_path(t_pipex *pipex, int in)
{
	char	*path;
	int		i;

	path = get_path(pipex);
	pipex->proc.path[in] = ft_split(path, ':');
	i = 0;
	while (pipex->proc.path[in][i] != NULL)
	{
		pipex->proc.path[in][i] = cat(pipex->proc.path[in][i],
				pipex->proc.cmd_args[in][0]);
		i++;
	}
}

int	is_path(char *str)
{
	return (is_abs_path(str) || is_r_path(str));
}
