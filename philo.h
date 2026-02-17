#ifndef PHILO_H
#define PHILO_H
#include <pthread.h>

struct s_fork {
	int				fork_id;
	pthread_mutex_t	fork_mutex;
} typedef t_fork;

struct s_philo {
	int				philo_id;
	int				eat_count;
	long long       last_meal_time;
	pthread_mutex_t meal_lock;
	t_fork			*r_fork;
	t_fork			*l_fork;
	pthread_t		thread;
	struct s_data	*data;
} typedef t_philo;

struct s_data {
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long long		start_time;
	int				stop_flag;
	pthread_mutex_t	write_lock;
	t_philo			*philosophers;
	t_fork			*forks;
} typedef t_data;


long long	get_timestamp_ms(void);
void		*init_forks(t_data *data);
void		*init_philos(t_data *data);
void		start_philos(t_data *data);
void		*monitor_routine(void *arg);
void		*philo_routine(void *arg);
void		sleep_ms(long long milisec, t_data *data);
int			is_finished(t_data *data);


#endif //PHILO_H
