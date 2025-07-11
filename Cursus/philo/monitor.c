/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:08:05 by lsanchez          #+#    #+#             */
/*   Updated: 2025/07/11 19:43:25 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_simulation *sim, int id, char *status)
{
	pthread_mutex_lock(&sim->print_lock);
	if (!sim->simulation_ended)
	{
		printf("%ld %d %s\n", get_current_time() - sim->start_time, id, status);
	}
	pthread_mutex_unlock(&sim->print_lock);
}

int	check_death(t_simulation *sim, int i)
{
	pthread_mutex_lock(&sim->philosophers[i].lock);
	if (get_current_time()
		- sim->philosophers[i].last_meal_time > sim->time_to_die)
	{
		print_status(sim, sim->philosophers[i].id, "died");
		pthread_mutex_lock(&sim->print_lock);
		sim->simulation_ended = 1;
		pthread_mutex_unlock(&sim->print_lock);
		pthread_mutex_unlock(&sim->philosophers[i].lock);
		return (1);
	}
	pthread_mutex_unlock(&sim->philosophers[i].lock);
	return (0);
}

int	check_meals(t_simulation *sim)
{
	int	i;

	if (sim->num_meals_to_finish == 0)
		return (0);
	i = -1;
	while (++i < sim->num_philosophers)
	{
		pthread_mutex_lock(&sim->philosophers[i].lock);
		if (sim->philosophers[i].meals_eaten < sim->num_meals_to_finish)
		{
			pthread_mutex_unlock(&sim->philosophers[i].lock);
			return (0);
		}
		pthread_mutex_unlock(&sim->philosophers[i].lock);
	}
	pthread_mutex_lock(&sim->print_lock);
	sim->simulation_ended = 1;
	pthread_mutex_unlock(&sim->print_lock);
	return (1);
}

void	monitor_simulation(t_simulation *sim)
{
	int	i;

	while (!simulation_finished(sim))
	{
		i = -1;
		while (++i < sim->num_philosophers)
		{
			if (check_death(sim, i) || check_meals(sim))
				break ;
		}
		precise_usleep(1);
	}
}

void	cleanup(t_simulation *sim)
{
	int	i;

	i = -1;
	while (++i < sim->num_philosophers)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		pthread_mutex_destroy(&sim->philosophers[i].lock);
	}
	pthread_mutex_destroy(&sim->print_lock);
	free(sim->philosophers);
	free(sim->forks);
}
