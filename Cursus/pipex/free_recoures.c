/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_recoures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:25:18 by lsanchez          #+#    #+#             */
/*   Updated: 2025/02/06 20:30:25 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_recourses(t_pipex *pipex)
{
	if (pipex->files.inf_fd != -1)
		close(pipex->files.inf_fd);
	if (pipex->files.outf_fd != -1)
		close(pipex->files.outf_fd);
	if (pipex->proc.pipes[0] != -1)
		close(pipex->proc.pipes[0]);
	if (pipex->proc.pipes[1] != -1)
		close(pipex->proc.pipes[1]);
	if (pipex->proc.path[0])
		free_char_matrix(pipex->proc.path[0]);
	if (pipex->proc.path[1])
		free_char_matrix(pipex->proc.path[1]);
	if (pipex->proc.cmd_args[0])
		free_char_matrix(pipex->proc.cmd_args[0]);
	if (pipex->proc.cmd_args[1])
		free_char_matrix(pipex->proc.cmd_args[1]);
}
