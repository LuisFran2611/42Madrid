/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedrano <mmedrano@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:28:52 by mmedrano          #+#    #+#             */
/*   Updated: 2024/08/27 20:35:19 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_MAP_H
# define VALIDATE_MAP_H

int	ft_is_printable(char c);
int	ft_validate_chars(char *chars);
int	ft_validate_map_line(char *map, char *chars, int size);
int	ft_validate_map(char *buffer);

#endif
