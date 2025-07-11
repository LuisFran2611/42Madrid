/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:13:27 by lsanchez          #+#    #+#             */
/*   Updated: 2025/07/11 19:43:19 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philosopher *philo)
{
	t_simulation	*sim;

	sim = philo->sim;
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(sim, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(sim, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(sim, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(sim, philo->id, "has taken a fork");
	}
}

void	philosopher_eat(t_philosopher *philo)
{
	t_simulation	*sim;

	sim = philo->sim;
	take_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->last_meal_time = get_current_time();
	print_status(sim, philo->id, "is eating");
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->lock);
	precise_usleep(sim->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;
	t_simulation	*sim;

	philo = (t_philosopher *)arg;
	sim = philo->sim;
	if (philo->id % 2 == 0)
		precise_usleep(sim->time_to_eat / 2);
	while (!simulation_finished(sim))
	{
		print_status(sim, philo->id, "is thinking");
		philosopher_eat(philo);
		print_status(sim, philo->id, "is sleeping");
		precise_usleep(sim->time_to_sleep);
	}
	return (NULL);
}

int	simulation_finished(t_simulation *sim)
{
	int	ret;

	pthread_mutex_lock(&sim->print_lock);
	ret = sim->simulation_ended;
	pthread_mutex_unlock(&sim->print_lock);
	return (ret);
}
