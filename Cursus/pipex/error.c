/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:43:17 by lsanchez          #+#    #+#             */
/*   Updated: 2025/02/10 13:30:57 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_fork(t_pipex *pipex)
{
	perror("Fork:");
	free_recourses(pipex);
	exit(EXIT_FAILURE);
}

void	error1(t_pipex *pipex)
{
	close(pipex->files.inf_fd);
	pipex->files.inf_fd = open("/dev/null", O_RDONLY);
	if (pipex->files.inf_fd == -1)
	{
		perror("/dev/null");
		exit(EXIT_FAILURE);
	}
	dup2(pipex->files.inf_fd, STDOUT_FILENO);
	close(pipex->files.inf_fd);
	error2(pipex, 0);
}

void	error2(t_pipex *pipex, int in)
{
	int	n_error;

	ft_putstr_fd(pipex->proc.exe, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(pipex->proc.cmd_args[in][0], 2);
	if (access(pipex->proc.cmd_args[in][0], F_OK) == 0)
	{
		if (access(pipex->proc.cmd_args[in][0], X_OK) == 0)
		{
			ft_putstr_fd(": No such file or directory\n", 2);
			n_error = 1;
		}
		else
		{
			ft_putstr_fd(": Permission denied\n", 2);
			n_error = 126;
		}
	}
	else
	{
		ft_putstr_fd(": command not found\n", 2);
		n_error = 127;
	}
	free_recourses(pipex);
	exit(n_error);
}
