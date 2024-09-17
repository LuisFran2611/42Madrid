/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedrano <mmedrano@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:57:13 by mmedrano          #+#    #+#             */
/*   Updated: 2024/08/27 20:19:37 by mmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

char	*ft_read_stdin(void);
char	*ft_read_buffer(char *buffer, int *lines_to_read);
char	*ft_realloc_input(char *input, int tot_size, char *buffer, int r_size);
int		ft_count_lines(char *buffer, int read_size);
int		main(int ac, char **av);
void	ft_process_file(char *filename);

#endif
