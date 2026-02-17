#include "philo.h"

int is_finished(t_data *data)
{
	int stop;

	pthread_mutex_lock(&data->write_lock);
	stop = data->stop_flag;
	pthread_mutex_unlock(&data->write_lock);
	return (stop);
}
