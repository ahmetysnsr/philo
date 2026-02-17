

#include <pthread.h>
#include <stdlib.h>

#include "philo.h"

void* init_forks(t_data *data) {
	int id_counter;

	data->forks = malloc(data->number_of_philosophers * sizeof(t_fork));
	if (data->forks == NULL)
		return NULL;
	id_counter = 0;
	while (id_counter < data->number_of_philosophers) {
		data->forks[id_counter].fork_id = id_counter;
		if (pthread_mutex_init(&data->forks[id_counter].fork_mutex, NULL))
			return NULL;
		id_counter++;
	}
	return data;
}

void *init_philos(t_data *data) {
	int id_counter;

	data->philosophers = malloc(data->number_of_philosophers * sizeof(t_philo));
	if (data->philosophers == NULL)
		return NULL;
	id_counter = 0;
	while (id_counter < data->number_of_philosophers) {
		data->philosophers[id_counter].philo_id = id_counter + 1;
		data->philosophers[id_counter].eat_count = 0;
		data->philosophers[id_counter].l_fork = &data->forks[id_counter];
		data->philosophers[id_counter].r_fork = &data->forks[(id_counter + 1) % data->number_of_philosophers];
		pthread_mutex_init(&data->philosophers[id_counter].meal_lock, NULL);
		data->philosophers[id_counter].last_meal_time = get_timestamp_ms();
		data->philosophers[id_counter].data = data;
		id_counter++;
	}
	return data;
}
