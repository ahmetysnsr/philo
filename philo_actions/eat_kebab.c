#include "../philo.h"

void	eat_kebab(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_lock);
	print_status(philo, "is eating");
	philo->last_meal_time = get_timestamp_ms();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->meal_lock);
	sleep_ms(philo->data->time_to_eat, philo->data);
}