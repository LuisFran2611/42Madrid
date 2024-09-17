/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:09:17 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/27 16:35:54 by mmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_MAP_H
# define CREATE_MAP_H

char	*ft_parse_chars(t_map *map, char *buffer);
int		ft_col_count(char *buffer);
int		ft_row_size(char *buffer);
int		ft_map_mem(t_map *map, int size, int l_size);
void	ft_fill_map(char *buffer, t_map *map, int size);
void	ft_create_map(char *buffer);

#endif
