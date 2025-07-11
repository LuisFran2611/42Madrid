/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:08:19 by lsanchez          #+#    #+#             */
/*   Updated: 2025/07/11 19:40:56 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_philosopher
{
	int					id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		lock;
	long				last_meal_time;
	int					meals_eaten;
	struct s_simulation	*sim;
}						t_philosopher;

typedef struct s_simulation
{
	int					num_philosophers;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					num_meals_to_finish;
	t_philosopher		*philosophers;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_lock;
	int					simulation_ended;
	long				start_time;
}						t_simulation;

long					get_current_time(void);
void					precise_usleep(long ms);
void					print_status(t_simulation *sim, int id, char *status);
void					take_forks(t_philosopher *philo);
void					philosopher_eat(t_philosopher *philo);
void					*philosopher_routine(void *arg);
int						check_death(t_simulation *sim, int i);
int						check_meals(t_simulation *sim);
int						simulation_finished(t_simulation *sim);
int						parse_arguments(int argc, char *argv[],
							t_simulation *sim);
int						init_simulation_data(t_simulation *sim);
int						init_philosophers(t_simulation *sim);
int						create_threads(t_simulation *sim);
long					ft_atol(const char *str);
int						ft_atoi(const char *str);
void					ft_putstr_fd(char *s, int fd);
void					monitor_simulation(t_simulation *sim);
void					cleanup(t_simulation *sim);
