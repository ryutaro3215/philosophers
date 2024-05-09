/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:18:21 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/09 14:51:33 by ryutaro3205      ###   ########.fr       */
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
	size_t	philo_num;
	size_t	tt_die;
	size_t	tt_eat;
	size_t	tt_sleep;
	size_t	eat_count;
}			t_env;

typedef struct s_philo
{
	pthread_t		thread;
	size_t			id;
	t_env			*env;
	size_t			eat_count;
	struct timeval	start;
	struct timeval	eat_time;
	t_mutex			*mutex;
}			t_philo;

/* parse argument*/
bool	is_number(char c);
bool	check_overflow(size_t n, char c);
bool	check_number(size_t *n, char *argv);
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
# endif
