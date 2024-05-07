/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:18:21 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/07 15:45:50 by ryutaro3205      ###   ########.fr       */
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

typedef struct s_counter
{
	int	count;
}		t_counter;

typedef struct s_mutex
{
	pthread_mutex_t mutex;
}			t_mutex;

typedef struct s_env
{
	size_t	philo_num;
	size_t	tt_die;
	size_t	tt_eat;
	size_t	tt_sleep;
	size_t	eat_count;
}		t_env;

typedef struct s_philo
{
	pthread_t		thread;
	size_t			id;
	t_env			*env;
	int				flag;
	t_mutex			*mutex;
}			t_philo;

/* parse argument*/
bool	is_number(char c);
bool	check_overflow(size_t n, char c);
bool	check_number(size_t *n, char *argv);
bool	check_arg(t_env *env, int argc, char **argv);

/* initialize */
void	init_mutex(t_mutex *mutex);
t_philo	*init_philo(t_env *env, t_mutex *mutex);

void	thread_philo(t_philo *philo, t_env *env);

void	*routine(void *arg);

# endif
