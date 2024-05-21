/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:59:06 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/16 18:21:51 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		print_message(philo, L_FORK);
		pthread_mutex_lock(philo->r_fork);
		print_message(philo, R_FORK);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_message(philo, R_FORK);
		pthread_mutex_lock(philo->l_fork);
		print_message(philo, L_FORK);
	}
	return ;
}

void	philo_eat(t_philo *philo)
{
	if (philo->env->is_dead)
		return ;
	if (philo->info->philo_num == 1)
	{
		my_usleep(philo->info->tt_die);
		return ;
	}
	take_fork(philo);
	pthread_mutex_lock(&philo->env->eat_mutex);
	philo->is_eating = true;
	philo->last_eat = get_current_time();
	print_message(philo, EATING);
	my_usleep(philo->info->tt_eat);
	philo->is_eating = false;
	philo->eat_count++;
	pthread_mutex_unlock(&philo->env->eat_mutex);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	philo_sleep(t_philo *philo)
{
	print_message(philo, SLEEPING);
	my_usleep(philo->info->tt_sleep);
}

void	philo_think(t_philo *philo)
{
	print_message(philo, THINKING);
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
