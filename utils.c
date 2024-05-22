/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:10:14 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/23 00:07:35 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	free_all(size_t i, t_philo *philo)
{
	pthread_mutex_destroy(&philo->env->print_mutex);
	pthread_mutex_destroy(&philo->env->dead_mutex);
	pthread_mutex_destroy(&philo->env->eat_mutex);
	free_env(i, philo);
}

void	free_env(size_t i, t_philo *philo)
{
	destroy_forks(i, philo->env);
	free(philo);
}

void	destroy_forks(size_t i, t_env *env)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		pthread_mutex_destroy(&env->forks[j]);
		j++;
	}
	free(env->forks);
}

void	my_usleep(size_t time)
{
	size_t	start;

	start = get_current_time();
	while (get_current_time() - start < time)
		usleep(100);
}

size_t	get_current_time(void)
{
	struct timeval	time;
	size_t			current_time;

	gettimeofday(&time, NULL);
	current_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (current_time);
}
