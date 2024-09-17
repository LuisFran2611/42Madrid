/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proces_dict.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:07:49 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/25 22:03:34 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCES_DICT_H
# define PROCES_DICT_H

char	*ft_strstr(char *str, char *to_find, int ind, int group);
void	ft_putstr(char *str, int ind, int group);
int		it_ok(char *str, char *to_find);
int		is_all_zero(char **matrix, int group, char *buffer, int flag);
int		is_negative(char *str, int ind, int group);

#endif
