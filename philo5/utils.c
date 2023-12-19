#include"philosophers.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->dead_flag == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	ft_print(t_arg *data, char *str, int id)
{
	int	time;

	pthread_mutex_lock(data->print);
	time = get_time() - data->start_time;
	if (!dead_loop(data->philo))
		printf("%d %d %s\n", time, id, str);
	pthread_mutex_unlock(data->print);
}

int	is_philo_dead(t_arg *data, int time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_time() - data->last_meal_time >= time_to_die)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(data->meal_lock);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	i = 0;
	j = 1;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		j *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{	
		res = res + str[i] - '0';
		if (str[i + 1] >= 48 && str[i + 1] <= 57)
			res = res * 10;
			i++;
	}
	return (res * j);
}