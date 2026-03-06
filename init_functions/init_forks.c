#include <stdlib.h>
#include "../philo.h"

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