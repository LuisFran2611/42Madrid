/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:13:27 by lsanchez          #+#    #+#             */
/*   Updated: 2025/07/08 21:13:27 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// Función para obtener el tiempo actual en milisegundos
long get_current_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

// Función para imprimir mensajes de estado
void print_status(t_simulation *sim, int id, char *status)
{
    pthread_mutex_lock(&sim->print_lock);
    if (!sim->simulation_ended)
    {
        printf("%ld %d %s\n", get_current_time() - sim->start_time, id, status);
    }
    pthread_mutex_unlock(&sim->print_lock);
}

// Función que ejecuta cada filósofo
void *philosopher_routine(void *arg)
{
    t_philosopher *philo = (t_philosopher *)arg;
    t_simulation *sim = philo->sim;

    while (!sim->simulation_ended)
    {
        // Pensar
        print_status(sim, philo->id, "is thinking");

        // Tomar tenedores
        pthread_mutex_lock(philo->left_fork);
        print_status(sim, philo->id, "has taken a fork");
        pthread_mutex_lock(philo->right_fork);
        print_status(sim, philo->id, "has taken a fork");

        // Comer
        pthread_mutex_lock(&philo->lock);
        philo->last_meal_time = get_current_time();
        print_status(sim, philo->id, "is eating");
        philo->meals_eaten++;
        pthread_mutex_unlock(&philo->lock);
        usleep(sim->time_to_eat * 1000);

        // Dejar tenedores
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);

        // Dormir
        print_status(sim, philo->id, "is sleeping");
        usleep(sim->time_to_sleep * 1000);
    }

    return NULL;
}

// Función para verificar si un filósofo murió
int check_death(t_simulation *sim, int i)
{
    pthread_mutex_lock(&sim->philosophers[i].lock);
    if (get_current_time() - sim->philosophers[i].last_meal_time > sim->time_to_die)
    {
        print_status(sim, sim->philosophers[i].id, "died");
        sim->simulation_ended = 1;
        pthread_mutex_unlock(&sim->philosophers[i].lock);
        return 1;
    }
    pthread_mutex_unlock(&sim->philosophers[i].lock);
    return 0;
}

// Función para verificar si todos los filósofos han comido suficientes veces
int check_meals(t_simulation *sim)
{
    if (sim->num_meals_to_finish == 0)
    {
        return 0;
    }
    for (int i = 0; i < sim->num_philosophers; i++)
    {
        pthread_mutex_lock(&sim->philosophers[i].lock);
        if (sim->philosophers[i].meals_eaten < sim->num_meals_to_finish)
        {
            pthread_mutex_unlock(&sim->philosophers[i].lock);
            return 0;
        }
        pthread_mutex_unlock(&sim->philosophers[i].lock);
    }
    sim->simulation_ended = 1;
    return 1;
}

int main(int argc, char *argv[])
{
    t_simulation sim;
    int i;

    // Manejo de argumentos
    if (argc < 5 || argc > 6)
    {
        fprintf(stderr, "Uso: %s numero_filosofos tiempo_para_morir tiempo_para_comer tiempo_para_dormir [numero_de_veces_que_deben_comer]\n", argv[0]);
        return 1;
    }

    sim.num_philosophers = atoi(argv[1]);
    sim.time_to_die = atol(argv[2]);
    sim.time_to_eat = atol(argv[3]);
    sim.time_to_sleep = atol(argv[4]);
    sim.num_meals_to_finish = (argc == 6) ? atoi(argv[5]) : 0;

    if (sim.num_philosophers <= 0 || sim.time_to_die <= 0 || sim.time_to_eat <= 0 || sim.time_to_sleep <= 0 || (argc == 6 && sim.num_meals_to_finish <= 0))
    {
        fprintf(stderr, "Error: argumentos inválidos\n");
        return 1;
    }

    // Inicialización
    sim.philosophers = malloc(sizeof(t_philosopher) * sim.num_philosophers);
    sim.forks = malloc(sizeof(pthread_mutex_t) * sim.num_philosophers);
    pthread_mutex_init(&sim.print_lock, NULL);
    sim.simulation_ended = 0;
    sim.start_time = get_current_time();

    for (i = 0; i < sim.num_philosophers; i++)
    {
        sim.philosophers[i].id = i + 1;
        sim.philosophers[i].left_fork = &sim.forks[i];
        sim.philosophers[i].right_fork = &sim.forks[(i + 1) % sim.num_philosophers];
        pthread_mutex_init(&sim.philosophers[i].lock, NULL);
        sim.philosophers[i].last_meal_time = sim.start_time;
        sim.philosophers[i].meals_eaten = 0;
        sim.philosophers[i].sim = &sim;
        pthread_mutex_init(&sim.forks[i], NULL);
    }

    // Crear hilos
    pthread_t threads[sim.num_philosophers];
    for (i = 0; i < sim.num_philosophers; i++)
    {
        if (pthread_create(&threads[i], NULL, philosopher_routine, &sim.philosophers[i]) != 0)
        {
            perror("Error al crear el hilo");
            return 1;
        }
        pthread_detach(threads[i]); // Desvincular para no tener que hacer join
    }

    // Monitorización (para detectar muertes o fin de la simulación)
    while (!sim.simulation_ended)
    {
        for (i = 0; i < sim.num_philosophers; i++)
        {
            if (check_death(&sim, i) || check_meals(&sim))
            {
                break;
            }
        }
        usleep(1000); // Espera un poco antes de la próxima verificación
    }

    // Limpieza
    for (i = 0; i < sim.num_philosophers; i++)
    {
        pthread_mutex_destroy(&sim.forks[i]);
        pthread_mutex_destroy(&sim.philosophers[i].lock);
    }
    pthread_mutex_destroy(&sim.print_lock);
    free(sim.philosophers);
    free(sim.forks);

    return 0;
}

