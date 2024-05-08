/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:49:53 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/08 12:44:47 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_mutex *mutex)
{
	pthread_mutex_init(&mutex->eat_mutex, NULL);
	pthread_mutex_init(&mutex->sleep_mutex, NULL);
	pthread_mutex_init(&mutex->think_mutex, NULL);
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
		i++;
	}
	return (philo);
}
