/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:12:57 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/22 17:54:56 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

bool	check_dead(t_env *env)
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

void	*monitoring(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		if (check_dead(philo->env) == true)
			return (NULL);
	}
	return (NULL);
}
