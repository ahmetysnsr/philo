cmake_minimum_required(VERSION 3.28)
project(philo C)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_C_STANDARD 11)

add_executable(Philo main.c
        routines/philo_routine.c
        routines/monitoring_routine.c
        utils/get_timestamp_ms.c
        init_functions/start_philos.c
        philo.h
        utils/sleep_ms.c
        utils/is_finished.c
        philo_actions/take_forks.c
        utils/print_status.c
        philo_actions/drop_forks.c
        philo_actions/eat_kebab.c
        philo_actions/take_nap.c
        philo_actions/think.c
        init_functions/init_forks.c
        init_functions/init_philos.c
        utils/clear_table.c
        utils/ft_atoi.c
        init_functions/init_data.c)
