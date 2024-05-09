/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:03:49 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/09 11:11:24 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q philo");
// }

int	main(int argc, char **argv)
{
	t_env	env;
	t_philo	*philo;
	t_mutex	mutex;

	if (!check_arg(&env, argc, argv) || !(init_mutex(&mutex, &env)))
		printf("Error\n");
	philo = init_philo(&env, &mutex);
	thread_philo(philo, &env);
	
	return (0);
}
