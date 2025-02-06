/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:12:10 by lsanchez          #+#    #+#             */
/*   Updated: 2025/02/06 18:44:12 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_files
{
	char		*inf;
	char		*outf;
	int			inf_fd;
	int			outf_fd;
}				t_files;

typedef struct s_process
{
	int			pipes[2];
	pid_t		pids[2];
	char		**cmd_args[2];
	char		**path[2];
	char		**envp;
}				t_process;

typedef struct s_pipex
{
	t_files		files;
	t_process	proc;
}				t_pipex;
void			check_files(t_pipex *pipex);
void			proces_path(t_pipex *pipex, int in);
void			create_proces(t_pipex *pipex);
void			free_recourses(t_pipex *pipex);
int				is_path(char *str);
char			*get_path(t_pipex *pipex);
void 			error_fork(t_pipex *pipex);
void 			error1(t_pipex *pipex);
void 			error2(t_pipex *pipex);

#endif
