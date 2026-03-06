#include <sys/time.h>
#include <unistd.h>

long long	get_timestamp_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (0);
	return (long long)tv.tv_sec * 1000 + (tv.tv_usec / 1000);
}
