/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:49:53 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/09 21:24:34 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_mutex(t_mutex *mutex, t_env *env)
{
	long	i;

	i = 0;
	while (i < env->philo_num)
	{
		pthread_mutex_init(&mutex->forks[i], NULL);
		i++;
	}
	if (!(i == env->philo_num))
	{
		while (i >= 0)
		{
			pthread_mutex_destroy(&mutex->forks[i]);
			i--;
		}
		return (false);
	}
	pthread_mutex_init(&mutex->eat_mutex, NULL);
	pthread_mutex_init(&mutex->sleep_mutex, NULL);
	pthread_mutex_init(&mutex->think_mutex, NULL);
	return (true);
}

t_philo	*init_philo(t_env *env, t_mutex *mutex)
{
	t_philo	*philo;
	long	i;

	philo = (t_philo *)malloc(sizeof(t_philo) * env->philo_num);
	i = 0;
	while (i < env->philo_num)
	{
		philo[i].id = i + 1;
		philo[i].env = env;
		philo[i].eat_count = 0;
		philo[i].mutex = mutex;
		philo[i].l_fork = &mutex->forks[i];
		if (i == 0)
			philo[i].r_fork = &mutex->forks[env->philo_num - 1];
		else
			philo[i].r_fork = &mutex->forks[i - 1];
		philo[i].start = get_current_time();
		philo[i].eat_time = get_current_time();
		i++;
	}
	return (philo);
}
