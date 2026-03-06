#include <unistd.h>
#include "../philo.h"

void sleep_ms(long long milisec, t_data *data)
{
	long long start;

	start = get_timestamp_ms();
	while ((get_timestamp_ms() - start) < milisec)
		usleep(100);
}
