/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:40:31 by lsanchez          #+#    #+#             */
/*   Updated: 2025/02/10 13:07:16 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exe_command1(t_pipex *pipex)
{
	dup2(pipex->files.inf_fd, STDIN_FILENO);
	dup2(pipex->proc.pipes[1], STDOUT_FILENO);
	close(pipex->files.inf_fd);
	close(pipex->proc.pipes[0]);
	close(pipex->proc.pipes[1]);
	execve(pipex->proc.cmd_args[0][0], pipex->proc.cmd_args[0],
		pipex->proc.envp);
	error1(pipex);
}

void	exe_command2(t_pipex *pipex)
{
	dup2(pipex->proc.pipes[0], STDIN_FILENO);
	dup2(pipex->files.outf_fd, STDOUT_FILENO);
	close(pipex->files.outf_fd);
	close(pipex->proc.pipes[0]);
	close(pipex->proc.pipes[1]);
	execve(pipex->proc.cmd_args[1][0], pipex->proc.cmd_args[1],
		pipex->proc.envp);
	error2(pipex, 1);
}

void	create_proces(t_pipex *pipex)
{
	if (pipe(pipex->proc.pipes) == -1)
		exit(EXIT_FAILURE);
	pipex->proc.pids[0] = fork();
	if (pipex->proc.pids[0] == -1)
		error_fork(pipex);
	if (pipex->proc.pids[0] == 0)
		exe_command1(pipex);
	pipex->proc.pids[1] = fork();
	if (pipex->proc.pids[1] == -1)
		error_fork(pipex);
	if (pipex->proc.pids[1] == 0)
		exe_command2(pipex);
	close(pipex->proc.pipes[0]);
	close(pipex->proc.pipes[1]);
	waitpid(pipex->proc.pids[0], &pipex->proc.status[0], 0);
	waitpid(pipex->proc.pids[1], &pipex->proc.status[1], 0);
	free_recourses(pipex);
}
