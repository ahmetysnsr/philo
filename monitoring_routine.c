#include <stdio.h>
#include <unistd.h>

#include "philo.h"

void    *monitor_routine(void *arg)
{
	t_data *data = (t_data *)arg;
	int i;

	while (1)
	{
		i = 0;
		while (i < data->number_of_philosophers)
		{
			pthread_mutex_lock(&data->philosophers[i].meal_lock);
			if (get_timestamp_ms() - data->philosophers[i].last_meal_time > data->time_to_die)
			{
				pthread_mutex_lock(&data->write_lock);
				data->stop_flag = 1;
				printf("%lld %d died\n", get_timestamp_ms() - data->start_time, data->philosophers[i].philo_id);
				pthread_mutex_unlock(&data->write_lock);
				pthread_mutex_unlock(&data->philosophers[i].meal_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&data->philosophers[i].meal_lock);
			i++;
		}
		usleep(1000);
	}
}
