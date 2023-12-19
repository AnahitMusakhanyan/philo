#include"philosophers.h"

void	malloc_error()
{
	printf("%s", "error allocating memory");
	return (1);
}

void	clear_data(t_arg *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

void	ft_exit(t_arg *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->[philo->print]);
	clear_data(data);
}