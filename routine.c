/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:59:06 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/22 18:06:12 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	dead_flag(t_env *env)
{
	pthread_mutex_lock(&env->dead_mutex);
	env->is_dead = true;
	pthread_mutex_unlock(&env->dead_mutex);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->eat_mutex);
	if (!check_dead(philo->env))
		printf("philo[%zu] eat_count[%zu]\n", philo->id, philo->eat_count);
	philo->eat_count++;
	if (philo->eat_count == philo->info->must_eat_count ||
		philo->info->must_eat == true)
		dead_flag(philo->env);
	pthread_mutex_unlock(&philo->env->eat_mutex);
}

void	philo_sleep(t_philo *philo)
{
	printf("philo[%zu] %s\n", philo->id, SLEEPING);
	my_usleep(philo->info->tt_sleep);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!check_dead(philo->env))
	{
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}
