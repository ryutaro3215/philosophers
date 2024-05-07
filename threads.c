/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:54:44 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/07 15:11:04 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_philo(t_philo *philo, t_env *env)
{
	size_t	i;

	i = 0;
	while (i < env->philo_num)
	{
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < env->philo_num)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
