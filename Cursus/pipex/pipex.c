/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:12:07 by lsanchez          #+#    #+#             */
/*   Updated: 2025/02/10 13:10:10 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
		return (1);
	pipex.proc.exe = argv[0];
	pipex.proc.envp = env;
	pipex.files.inf = argv[1];
	pipex.proc.cmd_args[0] = ft_split_quote(argv[2]);
	pipex.proc.cmd_args[1] = ft_split_quote(argv[3]);
	pipex.files.outf = argv[4];
	check_files(&pipex);
	if (!is_path(pipex.proc.cmd_args[0][0]))
		proces_path(&pipex, 0);
	if (!is_path(pipex.proc.cmd_args[1][0]))
		proces_path(&pipex, 1);
	create_proces(&pipex);
	exit(pipex.proc.status[1] % 255);
}
