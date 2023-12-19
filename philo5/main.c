#include"philosophers.h"

int	parse(char **av, int ac, t_arg *data)
{
	data->num_philo = ft_atoi(av[1]);
	if (data->num_philo > 200 || data->num_philo < 0)
		return (1);
	if (data->num_philo == 1)
	{
		pthread_mutex_lock(data->right_f);
		ft_print(data, "took the right fork", data->philo->id);
		pthread_mutex_unlock(data->right_f);
		ft_print(data, "has died", 1);
		return (0);
	}
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (data->time_to_die <= 0 || data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (1);
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = 0;
	return (0);
}



int main(int ac, char **av)
{
	t_arg	*data;
	t_philo	*philo;
	int		time;

	if (ac != 5 && ac != 6)
		return (1);
	data = malloc(sizeof(t_arg));
	if (!data)
		malloc_error();
	philo = malloc(sizeof(t_philo));
	if (!philo)
		malloc_error();
	parse(av, ac, data);
	time = get_time();
	malloc_data(data);
	make_threads(data);
	init_mutex(data);

}