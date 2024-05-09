/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:54:44 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/09 14:50:55 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_philo(t_philo *philo, t_env *env)
{
	size_t		i;
	pthread_t	monitor;

	pthread_create(&monitor, NULL, &monitoring, philo);
	i = 0;
	while (i < env->philo_num)
	{
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < env->philo_num)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
