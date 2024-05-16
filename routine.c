/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:59:06 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/16 14:08:55 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	philo_eat(t_philo *philo)
{
	if (philo->env->is_dead)
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
	}
	printf("%zu %zu has taken a first fork\n", get_current_time() - philo->start_time, philo->id);
	printf("%zu %zu has taken a second fork\n", get_current_time() - philo->start_time, philo->id);
	pthread_mutex_lock(&philo->env->eat_mutex);
	philo->is_eating = true;
	philo->last_eat = get_current_time();
	printf("%zu %zu is eating\n", get_current_time() - philo->start_time, philo->id);
	my_usleep(philo->info->tt_eat);
	philo->is_eating = false;
	philo->eat_count++;
	pthread_mutex_unlock(&philo->env->eat_mutex);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	philo_sleep(t_philo *philo)
{
	if (philo->env->is_dead)
		return ;
	pthread_mutex_lock(&philo->env->print_mutex);
	printf("%zu %zu is sleeping\n", get_current_time() - philo->start_time, philo->id);
	my_usleep(philo->info->tt_sleep);
	pthread_mutex_unlock(&philo->env->print_mutex);
}

void	philo_think(t_philo *philo)
{
	if (philo->env->is_dead)
		return ;
	pthread_mutex_lock(&philo->env->print_mutex);
	printf("%zu %zu is thinking\n", get_current_time() - philo->start_time, philo->id);
	pthread_mutex_unlock(&philo->env->print_mutex);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_env	*env;

	philo = (t_philo *)arg;
	env = philo->env;
	while (!check_dead_flag(env))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
