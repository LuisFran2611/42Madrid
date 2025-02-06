/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_recoures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:25:18 by lsanchez          #+#    #+#             */
/*   Updated: 2025/02/06 17:48:07 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void doble_free1(t_pipex *pipex)
{
	int j;
	
	j=0;
	while (pipex->proc.path[0][j])
	{
		if (pipex->proc.cmd_args[0][0] == pipex->proc.path[0][j])
		{
			pipex->proc.cmd_args[0][0] = NULL;
			break;
		}
		j++;
	}
}
void doble_free2(t_pipex *pipex)
{
	int j = 0;
		while (pipex->proc.path[1][j])
		{
			if (pipex->proc.cmd_args[1][0] == pipex->proc.path[1][j])
			{
				pipex->proc.cmd_args[1][0] = NULL;
				break;
			}
			j++;
		}
}
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
	if (pipex->proc.path[0] && pipex->proc.cmd_args[0])
		doble_free1(pipex);
	if (pipex->proc.path[1] && pipex->proc.cmd_args[1])
		doble_free2(pipex);
	if (pipex->proc.path[0])
		free_char_matrix(pipex->proc.path[0]);
	if (pipex->proc.path[1])
		free_char_matrix(pipex->proc.path[1]);
	if (pipex->proc.cmd_args[0])
		free_char_matrix(pipex->proc.cmd_args[0]);
	if (pipex->proc.cmd_args[1])
		free_char_matrix(pipex->proc.cmd_args[1]);
}


