/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:18:21 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/03 23:32:10 by ryutaro3205      ###   ########.fr       */
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

typedef struct s_arg
{
	size_t			philo_num;
	size_t			die_time;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			must_eat_count;
}			t_arg;

typedef struct s_env
{
	pthread_mutex_t *forks;
	size_t			fork_num;
}		t_env;

typedef struct s_mutex
{
	pthread_mutex_t *eat_mutex;
	pthread_mutex_t *write_mutex;
	pthread_mutex_t *dead_mutex;
}		t_mutex;

typedef struct s_philp
{
	size_t			id;
	size_t			eat_count;
	t_arg			*arg;
	t_env			*env;
	pthread_t		thread;
	t_mutex			*mutex;
	bool			is_eating;
	struct timeval	last_eat;
	struct timeval	next_eat;
}		t_philo;

/* parse argument*/
bool	is_number(char c);
bool	check_overflow(size_t n, char c);
bool	check_number(size_t *n, char *argv);
bool	check_arg(t_arg *arg, int argc, char **argv);

/* init */
void	free_forks(size_t i, t_env *env);
bool	init_fork(t_arg arg, t_env *env);
t_philo	*init_philo(t_arg *arg, t_env *env, t_mutex *mutex);

# endif
