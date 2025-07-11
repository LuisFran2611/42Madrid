/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:08:10 by lsanchez          #+#    #+#             */
/*   Updated: 2025/07/11 19:13:40 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_simulation	sim;

	if (parse_arguments(argc, argv, &sim) != 0)
		return (1);
	if (init_simulation_data(&sim) != 0)
	{
		cleanup(&sim);
		return (1);
	}
	if (init_philosophers(&sim) != 0)
	{
		cleanup(&sim);
		return (1);
	}
	if (create_threads(&sim) != 0)
	{
		cleanup(&sim);
		return (1);
	}
	monitor_simulation(&sim);
	cleanup(&sim);
	return (0);
}
