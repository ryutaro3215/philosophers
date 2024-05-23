/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:59:06 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/23 17:19:27 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		print_message(philo, philo->id, FORK);
		pthread_mutex_lock(philo->r_fork);
		print_message(philo, philo->id, FORK);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_message(philo, philo->id, FORK);
		pthread_mutex_lock(philo->l_fork);
		print_message(philo, philo->id, FORK);
	}
	return ;
}

void	philo_eat(t_philo *philo)
{
	size_t	start;

	start = get_current_time();
	if (philo->info->philo_num == 1)
	{
		dead_flag(philo->env);
		return ;
	}
	take_fork(philo);
	print_message(philo, philo->id, EATING);
	pthread_mutex_lock(&philo->env->time_mutex);
	philo->last_eat = get_current_time();
	pthread_mutex_unlock(&philo->env->time_mutex);
	my_usleep(philo->info->tt_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_lock(&philo->env->count_mutex);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->env->count_mutex);
}

void	philo_sleep(t_philo *philo)
{
	print_message(philo, philo->id, SLEEPING);
	my_usleep(philo->info->tt_sleep);
	return ;
}

void	philo_think(t_philo *philo)
{
	print_message(philo, philo->id, THINKING);
	return ;
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!check_dead_flag(philo->env))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
