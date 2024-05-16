/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:12:57 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/16 19:25:57 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	print_message(t_philo *philo, char *str)
{
	size_t	time;

	pthread_mutex_lock(&philo->env->print_mutex);
	time = get_current_time() - philo->start_time;
	if (!check_dead_flag(philo->env))
		printf("%zu %zu %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->env->print_mutex);
}

bool	check_philo_dead(t_philo *philo, t_info *info, t_env *env)
{
	size_t	i;
	size_t	time;

	i = 0;
	time = get_current_time();
	pthread_mutex_lock(&env->dead_mutex);
	while (i < info->philo_num)
	{
		if (time - philo[i].last_eat >= info->tt_die)
		{
			printf("%zu %zu %s\n", time - philo[i].start_time,
				philo[i].id, DEAD);
			env->is_dead = true;
			pthread_mutex_unlock(&env->dead_mutex);
			return (true);
		}
		i++;
	}
	pthread_mutex_unlock(&env->dead_mutex);
	return (false);
}

bool	check_all_eat(t_philo *philo, t_info *info, t_env *env)
{
	size_t	i;
	size_t	finish_eat_philo;

	i = 0;
	finish_eat_philo = 0;
	if (info->must_eat == false)
		return (false);
	while (i < philo->info->philo_num)
	{
		pthread_mutex_lock(&env->eat_mutex);
		if (philo[i].eat_count >= info->must_eat_count)
			finish_eat_philo++;
		pthread_mutex_unlock(&env->eat_mutex);
		i++;
	}
	if (finish_eat_philo == info->philo_num)
	{
		pthread_mutex_lock(&env->dead_mutex);
		printf("All philosophers have eaten %zu times\n", info->must_eat_count);
		env->is_dead = true;
		pthread_mutex_unlock(&env->dead_mutex);
		return (true);
	}
	return (false);
}

bool	check_dead_flag(t_env *env)
{
	pthread_mutex_lock(&env->dead_mutex);
	if (env->is_dead)
	{
		pthread_mutex_unlock(&env->dead_mutex);
		return (true);
	}
	pthread_mutex_unlock(&env->dead_mutex);
	return (false);
}

void	*monitoring(void *arg)
{
	t_philo	*philo;
	t_info	*info;
	t_env	*env;

	philo = (t_philo *)arg;
	info = philo->info;
	env = philo->env;
	while (!check_dead_flag(env))
	{
		if (check_all_eat(philo, info, env)
			|| check_philo_dead(philo, info, env))
			break ;
	}
	return (NULL);
}
