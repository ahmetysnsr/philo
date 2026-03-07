

#include <pthread.h>
#include <stdio.h>
#include "../philo.h"

void	start_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&data->philosophers[i].thread, NULL,
				philo_routine, &data->philosophers[i]) != 0)
		{
			pthread_mutex_lock(&data->write_lock);
			data->stop_flag = 1;
			pthread_mutex_unlock(&data->write_lock);
			printf("Error: Failed to create thread for philosopher %d\n", i + 1);
			break ;
		}
		i++;
	}
	while (--i >= 0)
		pthread_join(data->philosophers[i].thread, NULL);
}
