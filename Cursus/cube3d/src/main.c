/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:26:00 by luf-sanc          #+#    #+#             */
/*   Updated: 2025/07/21 10:42:20 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * @brief Main function of the cub3D project.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return int The exit status of the program.
 */
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./cub3D <map.cub>\n", 2);
		return (1);
	}
	// TODO: Check file extension .cub
	
	// Initialize game structure
	ft_memset(&game, 0, sizeof(t_game));
	game.player = ft_calloc(1, sizeof(t_player));
	if (!game.player)
		exit_error("Failed to allocate memory for player.", &game);

	// Parse the scene file
	parse_file(argv[1], &game);

	// Initialize MLX, window, player, etc.
	init_game(&game);

	mlx_loop_hook(game.mlx, &render_frame, &game); // For continuous rendering
	mlx_hook(game.win, 2, 1L<<0, &key_press_hook, &game); // Key press
	mlx_hook(game.win, 17, 0, &close_window_hook, &game); // Window close
	mlx_loop(game.mlx);

	cleanup(&game);
	return (0);
}