/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dict.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:04:14 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/25 21:14:39 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_DICT_H
# define PRINT_DICT_H

int		char_index(char *buffer, int group);
int		check_index(char *buffer, int group);
int		traslate(char *buffer, char c, char d, int group);
int		print_nb(char *str, int group, char *buffer);
void	proces_dict(char **matrix, int group, char *buffer);

#endif
