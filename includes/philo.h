/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:18:21 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/09 21:25:42 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_mutex
{
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	sleep_mutex;
	pthread_mutex_t	think_mutex;
	pthread_mutex_t *forks;
}			t_mutex;

typedef struct s_env
{
	long	philo_num;
	long	tt_die;
	long	tt_eat;
	long	tt_sleep;
	long	eat_count;
}			t_env;

typedef struct s_philo
{
	size_t			id;
	t_env			*env;
	long			eat_count;
	size_t			start;
	size_t			eat_time;
	pthread_t		thread;
	t_mutex			*mutex;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}			t_philo;

/* parse argument*/
bool	is_number(char c);
bool	check_overflow(long n, char c);
bool	check_number(long *n, char *argv);
bool	check_arg(t_env *env, int argc, char **argv);

/* initialize */
bool	init_mutex(t_mutex *mutex, t_env *env);
t_philo	*init_philo(t_env *env, t_mutex *mutex);

/* thread */
void	thread_philo(t_philo *philo, t_env *env);

/* routine */
void	eating(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	*routine(void *arg);

/* monitor */
void	*monitoring(void *arg);

/* utils */
size_t	get_current_time(void);
# endif
