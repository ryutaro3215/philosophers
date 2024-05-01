/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:30:15 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/05/01 19:58:00 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_forks(size_t i, t_env *env)
{
	while (i > 0)
	{
		pthread_mutex_destroy(&env->forks[i]);
		i--;
	}
	free(env->forks);
}

bool	init_fork(t_arg arg, t_env *env)
{
	size_t	i;

	i = 0;
	env->fork_num = arg.philo_num;
	env->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * env->fork_num);
	while (i < env->fork_num)
	{
		if (pthread_mutex_init(&env->forks[i], NULL) != 0)
			return (false);
		i++;
	}
	if (i != env->fork_num)
		free_forks(i, env);
	return (true);
}