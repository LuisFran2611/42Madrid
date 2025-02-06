/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:43:17 by lsanchez          #+#    #+#             */
/*   Updated: 2025/02/06 18:49:43 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error_fork(t_pipex *pipex)
{
	perror("Fork:");
	free_recourses(pipex);
	exit(EXIT_FAILURE);
}
void error1(t_pipex *pipex)
{
    perror(pipex->proc.cmd_args[0][0]);
    free_recourses(pipex);
    exit(0);
}

void error2(t_pipex *pipex)
{
    perror(pipex->proc.cmd_args[1][0]);
    free_recourses(pipex);
    if(access(pipex->proc.path[1][0], X_OK) == 0)
        exit(EXIT_FAILURE);
    exit(127);
}