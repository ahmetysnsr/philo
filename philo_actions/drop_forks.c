#include "../philo.h"

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->r_fork->fork_mutex);
	pthread_mutex_unlock(&philo->l_fork->fork_mutex);
}