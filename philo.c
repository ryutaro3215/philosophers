/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:03:49 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/07 19:38:16 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q philo");
}

int	main(int argc, char **argv)
{
	t_env	env;
	t_philo	*philo;
	t_mutex	mutex;
	t_counter	counter;

	if (!check_arg(&env, argc, argv))
		printf("Error: Invalid argument\n");
	else
		printf("Success\n");
	init_mutex(&mutex);
	counter.count = 0;
	philo = init_philo(&env, &mutex);
	thread_philo(philo, &env);
	return (0);
}
