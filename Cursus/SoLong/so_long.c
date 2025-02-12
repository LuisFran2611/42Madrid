/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:29:33 by lsanchez          #+#    #+#             */
/*   Updated: 2025/02/11 12:13:29 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	standar_output(t_game *game)
{
	free_resources(game);
	exit(0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		standar_output(game);
	else if (is_a_move(keycode))
	{
		gen_move(keycode, game);
	}
	return (0);
}

int	close_window(t_game *game)
{
	free_resources(game);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2 && check_path(argv[1]))
	{
		game.data.path = argv[1];
		if (inicialice(&game))
		{
			standar_output(&game);
			return (1);
		}
		mlx_key_hook(game.data.win_ptr, handle_keypress, &game.data);
		mlx_hook(game.data.win_ptr, 17, 0, close_window, &game.data);
		mlx_loop(game.data.mlx_ptr);
	}
	else
	ft_printf("Error\nNumero de argumentos de entrada no valido\n");
	return (0);
}
