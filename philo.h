#ifndef PHILO_H
#define PHILO_H
#include <pthread.h>

typedef struct s_fork {
	int				fork_id;
	pthread_mutex_t	fork_mutex;
} t_fork;

typedef struct s_philo {
	int				philo_id;
	int				eat_count;
	long long       last_meal_time;
	pthread_mutex_t meal_lock;
	t_fork			*r_fork;
	t_fork			*l_fork;
	pthread_t		thread;
	struct s_data	*data;
} t_philo;

typedef struct s_data {
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
} t_data;

t_data		*init_data(int argc, char **argv);
long long	get_timestamp_ms(void);
void		*init_forks(t_data *data);
void		*init_philos(t_data *data);
void		start_philos(t_data *data);
void		*monitor_routine(void *arg);
void		*philo_routine(void *arg);
void		sleep_ms(long long milisec, t_data *data);
int			is_finished(t_data *data);
int			print_safe(t_data *data, char *str);
void		print_status(t_philo *philo, char *status);
void		take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);
void		eat_kebab(t_philo *philo);
void		take_nap(t_philo *philo);
void		think(t_philo *philo);
void		clear_table(t_data *data);
int			ft_atoi(const char *str);





#endif //PHILO_H
