#include <stdlib.h>
#include <pthread.h>

#include "../philo.h"

void	clear_table(t_data *data)
{
	int i;

	if (!data)
		return ;
	i = 0;
	if (data->forks && data->philosophers)
	{
		while (i < data->number_of_philosophers)
		{
			pthread_mutex_destroy(&data->forks[i].fork_mutex);
			pthread_mutex_destroy(&data->philosophers[i].meal_lock);
			i++;
		}
	}
	pthread_mutex_destroy(&data->write_lock);
	free(data->forks);
	free(data->philosophers);
	free(data);
}