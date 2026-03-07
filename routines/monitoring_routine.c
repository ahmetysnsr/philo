#include <stdio.h>
#include <unistd.h>

#include "../philo.h"

void    *monitor_routine(void *arg)
{
	t_data *data = (t_data *)arg;
	int i;
	int finished_eating;

	while (1)
	{
		i = 0;
		finished_eating = 0;
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
			if (data->number_of_times_each_philosopher_must_eat != -1
				&& data->philosophers[i].eat_count >= data->number_of_times_each_philosopher_must_eat)
				finished_eating++;
			pthread_mutex_unlock(&data->philosophers[i].meal_lock);
			i++;
		}
		if (data->number_of_times_each_philosopher_must_eat != -1
			&& finished_eating == data->number_of_philosophers)
		{
			pthread_mutex_lock(&data->write_lock);
			data->stop_flag = 1;
			pthread_mutex_unlock(&data->write_lock);
			return (NULL);
		}
		usleep(1000);
	}
}
