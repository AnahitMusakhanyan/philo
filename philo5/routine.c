#include"philosophers.h"

void	eat(t_arg *data)
{
	if (is_philo_dead(data, data->time_to_die));
		ft_print(data, "died", data->philo->id);
	pthread_mutex_lock(data->right_f);
	ft_print(data, "took the right fork", data->philo->id);
	pthread_mutex_lock(data->left_f);
	printf("%d", data->philo->id);
	ft_print(data, "took the left fork", data->philo->id);
	ft_print(data, "is eating", data->philo->id);
	pthread_mutex_lock(data->meals_had);
	data->philo->meals_had++;
	pthread_mutex_unlock(data->meals_had);
	pthread_mutex_lock(data->last_meal_time);
	philo->last_meal = get_time();
	pthread_mutex_unlock(data->last_meal_time);
	ft_usleep(data->time_to_eat);
	pthread_mutex_unlock(data->right_f);
	pthread_mutex_unlock(data->left_f);
}

void	ft_sleep(t_arg *data)
{
	ft_usleep(data->time_to_sleep);
	ft_print(data, "is sleeping", data->philo->id);
}

void	think(t_arg *data)
{
	ft_print(data, "is thinking", data->philo->id);
}

void	*start_routine(t_arg *data)
{
	int	i;

	i = -1;
	if (philo->id % 2 == 0)
		ft_usleep(10);
	while (++i < data->philo->num_philo && is_philo_dead(data, data->time_to_die))
	{
		eat(data);
		if (is_philo_dead(data, data->time_to_die));
			ft_print(data, "died", data->philo->id);
		ft_sleep(data);
		if (is_philo_dead(data, data->time_to_die));
			ft_print(data, "died", data->philo->id);
		think(data);
		if (is_philo_dead(data, data->time_to_die));
			ft_print(data, "died", data->philo->id);
	}
	return ((void *)(0));
}