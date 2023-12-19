# ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<pthread.h>
# include<sys/time.h>

typedef struct	s_philo
{
	int	id;
	int	meals_had;
	int	last_meal;
	int	lock;
}				t_philo;

typedef struct s_arg
{
	struct	s_philo	*philo;
	pthread_t		*thread;
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				death_time;
	int				start_time;
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t print;
	pthread_mutex_t left_f;
	pthread_mutex_t	right_f;
	pthread_mutex_t meals_had;
	pthread_mutex_t	last_eat_time;
	pthread_mutex_t *forks;
}				t_arg;

// init

void	malloc_data(t_arg *data);
void	make_threads(t_arg *data);
void	init_mutex(t_arg *data);

// routine

void	*start_routine(t_arg *data);
void	think(t_arg *data);
void	ft_sleep(t_arg *data);
void	eat(t_arg *data);

// error

void	malloc_error();
void	clear_data(t_arg *data);
void	ft_exit(t_arg *data);

// utils

int	dead_loop(t_philo *philo);
void	ft_print(t_arg *data, char *str, int id);
int	is_philo_dead(t_arg *data, int time_to_die);
int	ft_atoi(const char *str);

// timer

void    get_time();
void	ft_usleep(int sleep_time);

#endif