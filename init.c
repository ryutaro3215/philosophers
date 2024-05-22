/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:28:21 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/22 19:20:57 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

t_philo	*init_philo(t_info *info, t_env *env)
{
	size_t	i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * info->philo_num);
	if (!philo)
		return (NULL);
	while (i < info->philo_num)
	{
		philo[i].id = i + 1;
		philo[i].start_time = get_current_time();
		philo[i].last_eat = get_current_time();
		philo[i].eat_count = 0;
		philo[i].l_fork = &env->forks[i];
		philo[i].env = env;
		philo[i].info = info;
		if (i == 0)
			philo[i].r_fork = &env->forks[info->philo_num - 1];
		else
			philo[i].r_fork = &env->forks[i - 1];
		i++;
	}
	return (philo);
}

bool	init_env(t_env *env, t_info *info)
{
	size_t	i;

	i = 0;
	env->forks = (pthread_mutex_t *)malloc
		(sizeof(pthread_mutex_t) * info->philo_num);
	if (!env->forks)
		return (false);
	while (i < info->philo_num)
	{
		if (pthread_mutex_init(&env->forks[i], NULL) != 0)
		{
			destroy_forks(i, env);
			return (printf("fail fork init"), false);
		}
		i++;
	}
	if (pthread_mutex_init(&env->dead_mutex, NULL) != 0
		|| pthread_mutex_init(&env->print_mutex, NULL) != 0
		|| pthread_mutex_init(&env->eat_mutex, NULL) != 0)
	{
		destroy_forks(i, env);
		return (printf("fail mutex"), false);
	}
	env->is_dead = false;
	return (true);
}
