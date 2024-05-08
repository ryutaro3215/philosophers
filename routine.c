/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:55:56 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/08 19:04:44 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->eat_mutex);
	printf("%zu is eating\n", philo->id);
	printf("%zu\n", philo->start.tv_sec);
	philo->flag = 1;
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
		sleep(1);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
