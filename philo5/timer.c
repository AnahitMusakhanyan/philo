#include"philosophers.h"



void    get_time()
{
	struct timeval time;

	if (gettimeofday(&time, 0))
		return (1);
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}

void	ft_usleep(int sleep_time)
{
	int	start;

	start = get_time();
	while (get_time() - start < sleep_time)
		usleep(500);
}