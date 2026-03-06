#include <stdlib.h>

#include "../philo.h"

t_data	*init_data(int argc, char **argv){
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		data->number_of_times_each_philosopher_must_eat = -1;
	data->stop_flag = 0;
	data->start_time = get_timestamp_ms();
	if (pthread_mutex_init(&data->write_lock, NULL))
	{
		free(data);
		return (NULL);
	}
	return (data);
}