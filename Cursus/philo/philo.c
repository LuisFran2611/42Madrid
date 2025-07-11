/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:13:27 by lsanchez          #+#    #+#             */
/*   Updated: 2025/07/11 18:44:21 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_status(t_simulation *sim, int id, char *status)
{
	pthread_mutex_lock(&sim->print_lock);
	if (!sim->simulation_ended)
	{
		printf("%ld %d %s\n", get_current_time() - sim->start_time, id, status);
	}
	pthread_mutex_unlock(&sim->print_lock);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;
	t_simulation	*sim;

	philo = (t_philosopher *)arg;
	sim = philo->sim;
	while (!sim->simulation_ended)
	{
		print_status(sim, philo->id, "is thinking");
		pthread_mutex_lock(philo->left_fork);
		print_status(sim, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(sim, philo->id, "has taken a fork");
		pthread_mutex_lock(&philo->lock);
		philo->last_meal_time = get_current_time();
		print_status(sim, philo->id, "is eating");
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->lock);
		usleep(sim->time_to_eat * 1000);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		print_status(sim, philo->id, "is sleeping");
		usleep(sim->time_to_sleep * 1000);
	}
	return (NULL);
}

int	check_death(t_simulation *sim, int i)
{
	pthread_mutex_lock(&sim->philosophers[i].lock);
	if (get_current_time() - sim->philosophers[i].last_meal_time > sim->time_to_die)
	{
		print_status(sim, sim->philosophers[i].id, "died");
		sim->simulation_ended = 1;
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
	sim->simulation_ended = 1;
	return (1);
}

