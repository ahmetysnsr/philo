

#include <pthread.h>

#include "philo.h"

void	start_philos(t_data *data) {
	int i;

	i = 0;
	while (i < data->number_of_philosophers) {
		if (pthread_create(&data->philosophers[i].thread, NULL, philo_routine, &data->philosophers[i]))
			return;
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers) {
		pthread_join(data->philosophers[i].thread, NULL);
		i++;
	}
}
