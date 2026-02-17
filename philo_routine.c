

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "philo.h"

void    *philo_routine(void *arg)
{
    t_philo *philo;
    t_data  *data;

    philo = (t_philo *)arg;
    data = philo->data;

    // Deadlock önlemek için asimetri (Çiftler biraz bekler)
    if (philo->philo_id % 2 == 0)
       usleep(1500);

    while (!is_finished(data))
    {
       // 1. Simülasyon bitti mi kontrolü
       pthread_mutex_lock(&data->write_lock);
       if (data->stop_flag) {
           pthread_mutex_unlock(&data->write_lock);
           break;
       }
       pthread_mutex_unlock(&data->write_lock);

       // 2. Çatalları Al
       pthread_mutex_lock(&philo->r_fork->fork_mutex);
       // Yazdırma Mutex'i
       pthread_mutex_lock(&data->write_lock);
       printf("%lld %d has taken a fork\n", get_timestamp_ms() - data->start_time, philo->philo_id);
       pthread_mutex_unlock(&data->write_lock);

       pthread_mutex_lock(&philo->l_fork->fork_mutex);
       pthread_mutex_lock(&data->write_lock);
       printf("%lld %d has taken a fork\n", get_timestamp_ms() - data->start_time, philo->philo_id);
       pthread_mutex_unlock(&data->write_lock);

       // 3. Yemek Ye
       pthread_mutex_lock(&philo->meal_lock); // Veri koruması
       pthread_mutex_lock(&data->write_lock);
       printf("%lld %d is eating\n", get_timestamp_ms() - data->start_time, philo->philo_id);
       pthread_mutex_unlock(&data->write_lock);
       philo->last_meal_time = get_timestamp_ms();
       philo->eat_count++;
       pthread_mutex_unlock(&philo->meal_lock);

       sleep_ms(data->time_to_eat, data);

       // 4. Çatalları Bırak
       pthread_mutex_unlock(&philo->r_fork->fork_mutex);
       pthread_mutex_unlock(&philo->l_fork->fork_mutex);

       // 5. Uyu ve Düşün
       pthread_mutex_lock(&data->write_lock);
       printf("%lld %d is sleeping\n", get_timestamp_ms() - data->start_time, philo->philo_id);
       pthread_mutex_unlock(&data->write_lock);
       sleep_ms(data->time_to_sleep, data);

       pthread_mutex_lock(&data->write_lock);
       printf("%lld %d is thinking\n", get_timestamp_ms() - data->start_time, philo->philo_id);
       pthread_mutex_unlock(&data->write_lock);
    }
    return (NULL);
}
