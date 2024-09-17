/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:00:24 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/27 12:46:11 by mmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "struct_square.h"

int		ft_min(int n1, int n2);
int		ft_check_sol(t_map *map, t_square *sol);
void	ft_print_map(t_map *map, t_square *sol, int size, int l_size);
void	ft_put_sol(t_map *map, t_square *sol);
void	ft_solve(t_map *map, int size, int l_size);

#endif
