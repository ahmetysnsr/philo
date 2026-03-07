#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
	{
		printf("Hata: Yanlış argüman sayısı.\n");
		return (1);
	}
	data = init_data(argc, argv);
	if (!data)
		return (1);
	data->start_time = get_timestamp_ms();
	if (!init_forks(data) || !init_philos(data))
	{
		clear_table(data);
		return (1);
	}
	pthread_t monitor_thread;
	pthread_create(&monitor_thread, NULL, monitor_routine, data);
	start_philos(data);
	pthread_join(monitor_thread, NULL);
	clear_table(data);
	return (0);
}
