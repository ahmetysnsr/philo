#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include "philo.h"













int main()
{
	t_data *data = malloc(sizeof(t_data));
	// 1. Önce verileri hazırla
	data->number_of_philosophers = 5;
	data->time_to_die = 400;
	data->time_to_eat = 200;
	data->time_to_sleep = 200;
	data->stop_flag = 0;
	data->start_time = get_timestamp_ms();

	// 2. Mutex'leri ve Hafızayı hazırla (Monitor'den ÖNCE!)
	pthread_mutex_init(&data->write_lock, NULL);
	init_forks(data);
	init_philos(data);

	// 3. Monitor thread'ini şimdi başlatabilirsin
	pthread_t monitor_thread;
	pthread_create(&monitor_thread, NULL, monitor_routine, data);

	// 4. Filozofları başlat
	start_philos(data);

	// 5. Her şey bittiğinde monitor'ü de join et
	pthread_join(monitor_thread, NULL);

	// Temizlik (Opsiyonel ama önerilir)
	// free_all(data);
	return (0);
}