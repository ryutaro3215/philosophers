/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:50:32 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/23 17:03:24 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DEAD "died"

typedef struct s_info
{
	size_t		philo_num;
	size_t		tt_die;
	size_t		tt_eat;
	size_t		tt_sleep;
	size_t		must_eat_count;
	bool		must_eat;
}		t_info;

typedef struct s_env
{
	bool			is_dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	count_mutex;
}		t_env;

typedef struct s_philo
{
	size_t			id;
	size_t			start_time;
	size_t			last_eat;
	size_t			eat_count;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_env			*env;
	t_info			*info;
}		t_philo;

/* parse_arg */
bool	is_number(char c);
bool	check_overflow(size_t n, char c);
bool	check_number(size_t *n, char *argv);
bool	check_arg(t_info *info, int argc, char **argv);

/* init */
t_philo	*init_philo(t_info *info, t_env *env);
bool	init_env(t_env *env, t_info *info);

/* threads */
void	philo_threads(t_philo *philo, t_info *info);

/* routine */
void	take_fork(t_philo *philo);
void	*routine(void *arg);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

/* monitor */
bool	check_all_eat(t_philo *philo);
bool	check_philo_dead(t_philo *philo);
void	*monitoring(void *arg);
void	print_message(t_philo *philo, size_t id, char *message);

/* dead */
void	dead_flag(t_env *env);
bool	check_dead_flag(t_env *env);


/* utils */
void	free_all(size_t i, t_philo *philo);
void	free_env(size_t i, t_philo *philo);
void	destroy_forks(size_t i, t_env *env);
void	my_usleep(size_t time);
size_t	get_current_time(void);

#endif
