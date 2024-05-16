/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:36:29 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/15 17:19:32 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	philo_threads(t_philo *philo, t_info *info)
{
	size_t	i;
	pthread_t	monitor;

	i = 0;
	if (pthread_create(&monitor, NULL, &monitoring, philo) != 0)
		free_env(info->philo_num, philo);
	while (i < info->philo_num)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			free_env(info->philo_num, philo);
		i++;
	}
	i = 0;
	pthread_join(monitor, NULL);
	while (i < info->philo_num)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
