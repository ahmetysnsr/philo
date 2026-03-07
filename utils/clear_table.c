#include <stdlib.h>
#include <pthread.h>

#include "../philo.h"

void clear_table(t_data *data)
{
	int i;

	if (!data)
		return ;
	if (data->forks)
	{
		i = -1;
		while (++i < data->number_of_philosophers)
			pthread_mutex_destroy(&data->forks[i].fork_mutex);
		free(data->forks);
	}
	if (data->philosophers)
	{
		i = -1;
		while (++i < data->number_of_philosophers)
			pthread_mutex_destroy(&data->philosophers[i].meal_lock);
		free(data->philosophers);
	}
	pthread_mutex_destroy(&data->write_lock);
	free(data);
}