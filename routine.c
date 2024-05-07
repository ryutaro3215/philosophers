/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:55:56 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/07 19:37:44 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	static int	count;

	count = 0;
	philo = (t_philo *)arg;
	while (1)
	{
		sleep(1);
		if (count > 30)
			break ;
		pthread_mutex_lock(&philo->mutex->mutex);
		printf("philo.id = %zu\n", philo->id);
		count++;
		printf("count = %d\n", count);
		pthread_mutex_unlock(&philo->mutex->mutex);
	}
	return (NULL);
}
