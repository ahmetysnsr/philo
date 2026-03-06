#include <stdio.h>

#include "../philo.h"

void print_status(t_philo *philo, char *status)
{
	long long timestamp;

	pthread_mutex_lock(&philo->data->write_lock);

	if (!philo->data->stop_flag)
	{
		timestamp = get_timestamp_ms() - philo->data->start_time;
		printf("%lld %d %s\n", timestamp, philo->philo_id, status);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
}