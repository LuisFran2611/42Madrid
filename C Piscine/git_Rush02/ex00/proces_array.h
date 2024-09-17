/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proces_array.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:55:43 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/25 18:37:54 by carlosg2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCES_ARRAY_H
# define PROCES_ARRAY_H

int		ft_strlen(char *str);
char	*add_zero(char *str, int size, int group);
void	print_matrix(char **matrix, int group);
void	proces_num(char *str, char *dic);

#endif
