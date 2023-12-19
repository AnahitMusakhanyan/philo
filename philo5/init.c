#include"philosophers.h"

void	init_mutex(t_arg *data)
{
	int	i;

	i = -1;
	while (++i < data->philo->num_philo)
	{
		if (pthread_mutex_init(data->forks[i], 0))
			return (1);
	}
	if (pthread_mutex_init(data->print, 0))
		return (1);
	if (pthread_mutex_init(data->dead_lock, 0))
		return (1);
	if (pthread_mutex_init(data->meals_had, 0))
		return (1);
	if (pthread_mutex_init(data->last_eat_time, 0))
		return (1);
	if (pthread_mutex_init(data->right_f, 0))
		return (1);
	if (pthread_mutex_init(data->left_f, 0))
		return (1);
}

void	make_threads(t_arg *data)
{
	int	i;

	i = -1;
	data->thread = malloc(sizeof(t_arg) * data->philo->num_philo);
	while (++i < data->philo->num_philo)
		pthread_create(&data->thread[i], 0, &start_routine, data);
	i = -1;
	while (++i < data->philo->num_philo)
		pthread_join(data->thread[i], 0);
}

void	malloc_data(t_arg *data)
{
	data->philo = malloc(sizeof(t_philo) * data->philo->num_philo);
	if (!data->philo)
		malloc_error();
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo->num_philo);
	if (!data->forks)
	{
		free(data->philo);
		malloc_error();
	}
}
