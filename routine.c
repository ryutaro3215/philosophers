/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:55:56 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/08 12:51:59 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->eat_mutex);
	printf("%zu is eating\n", philo->id);
	pthread_mutex_unlock(&philo->mutex->eat_mutex);
}
void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->think_mutex);
	printf("%zu is thinking\n", philo->id);
	pthread_mutex_unlock(&philo->mutex->think_mutex);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->sleep_mutex);
	printf("%zu is sleeping\n", philo->id);
	pthread_mutex_unlock(&philo->mutex->sleep_mutex);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sleep(2);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
