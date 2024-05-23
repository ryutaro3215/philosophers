/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:12:57 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/23 17:13:06 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	print_message(t_philo *philo, size_t id, char *message)
{
	size_t	current_time;

	current_time = get_current_time();
	if (check_dead_flag(philo->env))
		return ;
	printf("%zu %zu %s\n", current_time - philo->start_time, id, message);
}

bool	check_philo_dead(t_philo *philo)
{
	size_t	i;
	size_t	time;

	i = 0;
	time = get_current_time();
	while (i < philo->info->philo_num)
	{
		pthread_mutex_lock(&philo->env->time_mutex);
		if (time - philo[i].last_eat > philo->info->tt_die)
		{
			pthread_mutex_unlock(&philo->env->time_mutex);
			dead_flag(philo->env);
			printf("%zu %zu %s\n", time - philo->start_time, i + 1, DEAD);
			return (true);	
		}
		pthread_mutex_unlock(&philo->env->time_mutex);
		i++;
	}
	return (false);
}

bool	check_all_eat(t_philo *philo)
{
	size_t	i;

	i = 0;
	if (philo->info->must_eat == false)
		return (false);
	while (i < philo->info->philo_num)
	{
		pthread_mutex_lock(&philo->env->count_mutex);
		if (philo[i].eat_count < philo->info->must_eat_count)
		{
			pthread_mutex_unlock(&philo->env->count_mutex);
			return (false);
		}
		pthread_mutex_unlock(&philo->env->count_mutex);
		i++;
	}
	dead_flag(philo->env);
	printf("All philosophers have eaten %zu times\n", philo->info->must_eat_count);
	return (true);
}

void	*monitoring(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		if (check_philo_dead(philo) || check_all_eat(philo))
			return (NULL);
	}
	return (NULL);
}
