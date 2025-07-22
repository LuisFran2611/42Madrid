/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:25:00 by luf-sanc          #+#    #+#             */
/*   Updated: 2025/07/21 10:46:52 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line/get_next_line.h"
# include "../minilibx/mlx.h"

// ------------------- DEFINES -------------------

# define SCREEN_WIDTH	800
# define SCREEN_HEIGHT	600

// Key codes
# define K_ESC			65307
# define K_W			119
# define K_A			97
# define K_S			115
# define K_D			100
# define K_LEFT			65361
# define K_RIGHT		65363

// ----------------- STRUCTURES ------------------

/**
 * @brief Holds data for an mlx image.
 */
typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

/**
 * @brief Stores texture paths and floor/ceiling colors.
 */
typedef struct s_scene
{
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	t_img			no_tex;
	t_img			so_tex;
	t_img			we_tex;
	t_img			ea_tex;
	int				floor_color;
	int				ceiling_color;
	int				elements_defined; // Use bit flags: 1=NO, 2=SO, 4=WE, 8=EA, 16=F, 32=C
}	t_scene;

/**
 * @brief Stores map data.
 */
typedef struct s_map
{
	char			**grid;
	int				width;
	int				height;
}	t_map;

/**
 * @brief Stores player data.
 */
typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}	t_player;

/**
 * @brief Main game structure.
 */
typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_scene			*scene;
	t_map			*map;
	t_player		*player;
}	t_game;

// ----------------- PROTOTYPES ------------------

// Parser
void	parse_file(char *file_path, t_game *game);

// Initialization
void	init_game(t_game *game);

// Error and cleanup
void	exit_error(char *message, t_game *game);
void	cleanup(t_game *game);

// Hooks
int		close_window_hook(t_game *game);
int		key_press_hook(int keycode, t_game *game);
void	move_player(int keycode, t_game *game);
void	rotate_player(int keycode, t_game *game);

// Renderer
int		render_frame(t_game *game);

// Raycasting
void	perform_raycasting(t_game *game, t_img *img);

#endif