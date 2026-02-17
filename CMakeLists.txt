cmake_minimum_required(VERSION 3.31)
project(Philo C)

set(CMAKE_C_STANDARD 11)

add_executable(Philo main.c
        philo_routine.c
        monitoring_routine.c
        init_functions.c
        get_timestamp_ms.c
        start_philos.c
        philo.h
        sleep_ms.c
        is_finished.c)
