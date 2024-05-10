/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:49:00 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/09 21:25:17 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_eat_count(t_philo *philo)
{
	long	i;

	i = 0;
	while (i < philo->env->philo_num)
	{
		if (philo[i].eat_count < philo->env->eat_count)
			return (false);
		i++;
	}
	return (true);
}

void	*monitoring(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_eat_count(philo))
			break ;
	}
	return (arg);
}
