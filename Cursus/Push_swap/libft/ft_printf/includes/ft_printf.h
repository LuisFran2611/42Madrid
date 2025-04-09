/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:29:01 by lsanchez          #+#    #+#             */
/*   Updated: 2024/09/29 21:20:15 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_print_char(char c, int *length);
void	ft_print_str(char *str, int *length);
void	ft_print_int(int num, int *length);
void	ft_print_ptr(size_t ptr, int *length);
void	ft_print_hex(unsigned int num, int *length, char x);
void	ft_print_uns_int(unsigned int num, int *length);
int		ft_printf(const char *str, ...);

#endif