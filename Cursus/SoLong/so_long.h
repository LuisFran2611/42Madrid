/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:51:20 by lsanchez          #+#    #+#             */
/*   Updated: 2025/01/25 11:25:40 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "libft/ft_printf/includes/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# define TILE_SIZE 32
# define T_ANIMACION 650

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
	char		*path;
}				t_data;

typedef struct s_player
{
	int			x;
	int			y;
	int			moves;
}				t_player;

typedef struct s_img
{
	void		*img_ptr;
	char		*data;
	int			width;
	int			height;
}				t_img;

typedef struct s_map
{
	char		**grid;
	int			height;
	int			width;
	int			spc_char[3];
}				t_map;

typedef struct s_env
{
	t_img		img_wall;
	t_img		img_floor;
	t_img		img_player;
	t_img		img_exit;
	t_img		img_col;
}				t_env;

typedef struct s_game
{
	t_data		data;
	t_env		env;
	t_player	player;
	t_map		map;
}				t_game;

int				check_map(t_game *game);
void			calc_map(t_game *game);
void			free_char_matrix(char **matrix);
int				is_rectangular(t_game *game);
int				inicialice(t_game *game);
void			draw_map(t_game *game);
void			gen_move(int keycode, t_game *game);
void			move_up(t_game *game);
void			move_down(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);
void			animate(t_game *game);
void			free_resources(t_game *game);
int				check_path(char *str);
void			img_up(t_game *game);
void			img_down(t_game *game);
void			img_left(t_game *game);
void			img_right(t_game *game);
int				is_valid(char **map_copy, int y[2]);
#endif // SO_LONG_H
