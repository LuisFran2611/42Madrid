#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

// Estructura para representar un filósofo
typedef struct s_philosopher
{
    int id;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t lock; // Mutex para proteger el acceso al filósofo
    long last_meal_time;
    int meals_eaten;
    struct s_simulation *sim;
} t_philosopher;

// Estructura para representar la simulación
typedef struct s_simulation
{
    int num_philosophers;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    int num_meals_to_finish; // 0 si no se proporciona el argumento opcional
    t_philosopher *philosophers;
    pthread_mutex_t *forks;
    pthread_mutex_t print_lock; // Mutex para controlar la impresión
    int simulation_ended;
    long start_time;
} t_simulation;

// Function prototypes

// philo.c
long	get_current_time(void);
void	print_status(t_simulation *sim, int id, char *status);
void	*philosopher_routine(void *arg);
int		check_death(t_simulation *sim, int i);
int		check_meals(t_simulation *sim);

// utils.c
int		parse_arguments(int argc, char *argv[], t_simulation *sim);
int		init_simulation_data(t_simulation *sim);
int		init_philosophers(t_simulation *sim);
int		create_threads(t_simulation *sim);

// utils2.c
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);

// monitor.c
void	monitor_simulation(t_simulation *sim);
void	cleanup(t_simulation *sim);
