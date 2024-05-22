/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:13:38 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/05/22 21:14:07 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	dead_flag(t_env *env)
{
	pthread_mutex_lock(&env->dead_mutex);
	env->is_dead = true;
	pthread_mutex_unlock(&env->dead_mutex);
}

bool	check_dead_flag(t_env *env)
{
	pthread_mutex_lock(&env->dead_mutex);
	if (env->is_dead == true)
	{
		pthread_mutex_unlock(&env->dead_mutex);
		return (true);
	}
	pthread_mutex_unlock(&env->dead_mutex);
	return (false);
}