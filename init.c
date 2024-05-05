/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:30:15 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/05/03 23:32:16 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_forks(size_t i, t_env *env)
{
	while (i > 0)
	{
		pthread_mutex_destroy(&env->forks[i]);
		i--;
	}
	free(env->forks);
}

bool	init_fork(t_arg arg, t_env *env)
{
	size_t	i;

	i = 0;
	env->fork_num = arg.philo_num;
	env->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * env->fork_num);
	while (i < env->fork_num)
	{
		if (pthread_mutex_init(&env->forks[i], NULL) != 0)
			return (false);
		i++;
	}
	if (i != env->fork_num)
		free_forks(i, env);
	return (true);
}

t_mutex	*init_mutex(t_env *env)
{
	t_mutex	*mutex;

	pthread_mutex_init(mutex->eat_mutex, NULL);
	pthread_mutex_init(mutex->write_mutex, NULL);
	pthread_mutex_init(mutex->dead_mutex, NULL);
	return (mutex);
}

t_philo	*init_philo(t_arg *arg, t_env *env, t_mutex *mutex)
{
	t_philo	*philo;
	size_t	i;
	philo = (t_philo *)malloc(sizeof(t_philo) * arg->philo_num);
	if (philo == NULL)
		return (NULL);
	i = 0;
	while (i < arg->philo_num)
	{
		philo[i].id = i;
		philo[i].eat_count = 0;
		philo[i].arg = arg;
		philo[i].env = env;
		philo[i].is_eating = false;
		gettimeofday(&philo[i].last_eat, NULL);
		philo[i].next_eat = philo[i].last_eat;
		philo[i].mutex = mutex;
		i++;
	}
	return (philo);
}
