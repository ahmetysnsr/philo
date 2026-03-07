NAME    = philo
CC      = gcc
CFLAGS  = -pthread

SRCS    = main.c \
          init_functions/init_data.c \
          init_functions/init_forks.c \
          init_functions/init_philos.c \
          init_functions/start_philos.c \
          philo_actions/drop_forks.c \
          philo_actions/eat_kebab.c \
          philo_actions/take_forks.c \
          philo_actions/take_nap.c \
          philo_actions/think.c \
          routines/monitoring_routine.c \
          routines/philo_routine.c \
          utils/clear_table.c \
          utils/ft_atoi.c \
          utils/get_timestamp_ms.c \
          utils/is_finished.c \
          utils/print_status.c \
          utils/sleep_ms.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all