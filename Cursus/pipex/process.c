/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:40:31 by lsanchez          #+#    #+#             */
/*   Updated: 2025/01/26 19:57:20 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exe_command1_path(t_pipex *pipex, int i)
{
	if (access(pipex->proc.path[0][i], X_OK) == 0)
	{
		pipex->proc.cmd_args[0][0] = pipex->proc.path[0][i];
		execve(pipex->proc.cmd_args[0][0], pipex->proc.cmd_args[0],
			pipex->proc.envp);
	}
}

void	exe_command2_path(t_pipex *pipex, int i)
{
	if (access(pipex->proc.path[1][i], X_OK) == 0)
	{
		pipex->proc.cmd_args[1][0] = pipex->proc.path[1][i];
		execve(pipex->proc.cmd_args[1][0], pipex->proc.cmd_args[1],
			pipex->proc.envp);
	}
}

void	exe_command1(t_pipex *pipex)
{
	int	i;

	dup2(pipex->files.inf_fd, STDIN_FILENO);
	dup2(pipex->proc.pipes[1], STDOUT_FILENO);
	close(pipex->files.inf_fd);
	close(pipex->proc.pipes[0]);
	close(pipex->proc.pipes[1]);
	if (is_path(pipex->proc.cmd_args[0][0]))
	{
		if (access(pipex->proc.cmd_args[0][0], X_OK) == 0)
			execve(pipex->proc.cmd_args[0][0], pipex->proc.cmd_args[0],
				pipex->proc.envp);
	}
	else
	{
		i = 0;
		while (pipex->proc.path[0][i] != NULL)
		{
			exe_command1_path(pipex, i);
			i++;
		}
	}
	perror("Error al ejecutar cmd1");
	free_recourses(pipex);
	exit(EXIT_FAILURE);
}

void	exe_command2(t_pipex *pipex)
{
	int	i;

	dup2(pipex->proc.pipes[0], STDIN_FILENO);
	dup2(pipex->files.outf_fd, STDOUT_FILENO);
	close(pipex->files.outf_fd);
	close(pipex->proc.pipes[0]);
	close(pipex->proc.pipes[1]);
	if (is_path(pipex->proc.cmd_args[1][0]))
	{
		if (access(pipex->proc.cmd_args[1][0], X_OK) == 0)
			execve(pipex->proc.cmd_args[1][0], pipex->proc.cmd_args[1],
				pipex->proc.envp);
	}
	else
	{
		i = 0;
		while (pipex->proc.path[1][i] != NULL)
		{
			exe_command2_path(pipex, i);
			i++;
		}
	}
	perror("Error al ejecutar cmd2");
	free_recourses(pipex);
	exit(EXIT_FAILURE);
}

void	create_proces(t_pipex *pipex)
{
	if (pipe(pipex->proc.pipes) == -1)
		exit(EXIT_FAILURE);
	pipex->proc.pids[0] = fork();
	if (pipex->proc.pids[0] == -1)
		exit(EXIT_FAILURE);
	if (pipex->proc.pids[0] == 0)
		exe_command1(pipex);
	pipex->proc.pids[1] = fork();
	if (pipex->proc.pids[1] == -1)
		exit(EXIT_FAILURE);
	if (pipex->proc.pids[1] == 0)
		exe_command2(pipex);
	free_recourses(pipex);
	waitpid(pipex->proc.pids[0], NULL, 0);
	waitpid(pipex->proc.pids[1], NULL, 0);
}
