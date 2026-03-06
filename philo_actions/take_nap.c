#include "../philo.h"

void	take_nap(t_philo *philo)
{
	print_status(philo, "is sleeping");
	sleep_ms(philo->data->time_to_sleep, philo->data);
}