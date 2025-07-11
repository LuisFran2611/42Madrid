#include "philo.h"

void	monitor_simulation(t_simulation *sim)
{
	int	i;

	while (!sim->simulation_ended)
	{
		i = -1;
		while (++i < sim->num_philosophers)
		{
			if (check_death(sim, i) || check_meals(sim))
				break ;
		}
		usleep(1000);
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