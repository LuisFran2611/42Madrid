/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:32:35 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/27 12:44:36 by mmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_MAP_H
# define PROCESS_MAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

ssize_t	ft_file_size(const char *file_name);
void	ft_process_map(char *file);

#endif
