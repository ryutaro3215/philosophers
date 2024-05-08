/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:49:53 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/08 21:19:46 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_mutex(t_mutex *mutex, t_env *env)
{
	size_t	i;

	i = 0;
	while (i < env->philo_num)
	{
		pthread_mutex_init(&mutex->forks[i], NULL);
		i++;
	}
	if (i != env->philo_num)
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
	size_t	i;

	philo = (t_philo *)malloc(sizeof(t_philo) * env->philo_num);
	i = 0;
	while (i < env->philo_num)
	{
		philo[i].id = i + 1;
		philo[i].env = env;
		philo[i].flag = 0;
		philo[i].mutex = mutex;
		gettimeofday(&philo[i].start, NULL);
		i++;
	}
	return (philo);
}
