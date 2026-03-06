

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "../philo.h"

void    *philo_routine(void *arg)
{
    t_philo *philo;
    t_data  *data;

    philo = (t_philo *)arg;
    data = philo->data;

    pthread_mutex_lock(&philo->meal_lock);
    philo->last_meal_time = get_timestamp_ms();
    pthread_mutex_unlock(&philo->meal_lock);

    if (philo->philo_id % 2 == 0)
       usleep(data->time_to_eat * 500);

    while (!is_finished(data))
    {
    	take_forks(philo);
    	eat_kebab(philo);
    	drop_forks(philo);
    	take_nap(philo);
		think(philo);
    }
    return (NULL);
}
