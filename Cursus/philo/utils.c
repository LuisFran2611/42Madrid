/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:08:15 by lsanchez          #+#    #+#             */
/*   Updated: 2025/07/11 19:12:23 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_arguments(int argc, char *argv[], t_simulation *sim)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Uso: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(" num_filos time_morir", 2);
		ft_putstr_fd(" time_comer time_dormir [num_comidas]\n", 2);
		return (1);
	}
	sim->num_philosophers = ft_atoi(argv[1]);
	sim->time_to_die = ft_atol(argv[2]);
	sim->time_to_eat = ft_atol(argv[3]);
	sim->time_to_sleep = ft_atol(argv[4]);
	sim->num_meals_to_finish = 0;
	if (argc == 6)
		sim->num_meals_to_finish = ft_atoi(argv[5]);
	if (sim->num_philosophers <= 0 || sim->time_to_die <= 0
		|| sim->time_to_eat <= 0 || sim->time_to_sleep <= 0 || (argc == 6
			&& sim->num_meals_to_finish <= 0))
	{
		ft_putstr_fd("Error: argumentos inválidos\n", 2);
		return (1);
	}
	return (0);
}

int	init_simulation_data(t_simulation *sim)
{
	sim->philosophers = malloc(sizeof(t_philosopher) * sim->num_philosophers);
	if (!sim->philosophers)
		return (1);
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->num_philosophers);
	if (!sim->forks)
	{
		free(sim->philosophers);
		return (1);
	}
	pthread_mutex_init(&sim->print_lock, NULL);
	sim->simulation_ended = 0;
	sim->start_time = get_current_time();
	return (0);
}

int	init_philosophers(t_simulation *sim)
{
	int	i;

	i = -1;
	while (++i < sim->num_philosophers)
	{
		sim->philosophers[i].id = i + 1;
		sim->philosophers[i].left_fork = &sim->forks[i];
		sim->philosophers[i].right_fork = &sim->forks[(i + 1)
			% sim->num_philosophers];
		pthread_mutex_init(&sim->philosophers[i].lock, NULL);
		sim->philosophers[i].last_meal_time = sim->start_time;
		sim->philosophers[i].meals_eaten = 0;
		sim->philosophers[i].sim = sim;
		pthread_mutex_init(&sim->forks[i], NULL);
	}
	return (0);
}

int	create_threads(t_simulation *sim)
{
	int			i;
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * sim->num_philosophers);
	if (!threads)
		return (1);
	i = -1;
	while (++i < sim->num_philosophers)
	{
		if (pthread_create(&threads[i], NULL, philosopher_routine,
				&sim->philosophers[i]) != 0)
		{
			ft_putstr_fd("Error al crear el hilo\n", 2);
			free(threads);
			return (1);
		}
		pthread_detach(threads[i]);
	}
	free(threads);
	return (0);
}
