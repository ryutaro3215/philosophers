/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:12:57 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/22 21:14:02 by rmatsuba         ###   ########.fr       */
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
	size_t	current_time;
	size_t	i;

	i = 0;
	current_time = get_current_time();
	while (i < philo->info->philo_num)
	{
		if (check_dead_flag(philo->env))
		{
			printf("%zu %zu %s\n", current_time - philo->start_time,
				philo->id, DEAD);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	check_all_eat(t_philo *philo)
{
	size_t	i;

	i = 0;
	pthread_mutex_lock(&philo->env->eat_mutex);
	if (!philo->info->must_eat)
	{
		pthread_mutex_unlock(&philo->env->eat_mutex);
		return (false);
	}
	while (i < philo->info->philo_num)
	{
		if (philo[i].eat_count <= philo[i].info->must_eat_count)
		{
			pthread_mutex_unlock(&philo->env->eat_mutex);
			return (false);
		}
		i++;
	}
	dead_flag(philo->env);
	printf("all philosoper ate %zu times\n", philo->info->must_eat_count);
	pthread_mutex_unlock(&philo->env->eat_mutex);
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
