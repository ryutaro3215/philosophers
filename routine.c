/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:59:06 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/22 23:52:00 by ryutaro3205      ###   ########.fr       */
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
	size_t	current_time;

	current_time = get_current_time();
	pthread_mutex_lock(&philo->env->eat_mutex);
	if (current_time - philo->last_eat <= philo->info->tt_die
		&& philo->info->philo_num != 1)
	{
		take_fork(philo);
		philo->eat_count++;
		print_message(philo, philo->id, EATING);
		philo->last_eat = get_current_time();
		my_usleep(philo->info->tt_eat);
		pthread_mutex_unlock(&philo->env->eat_mutex);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	else
	{
		dead_flag(philo->env);
		pthread_mutex_unlock(&philo->env->eat_mutex);
		return ;
	}
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
