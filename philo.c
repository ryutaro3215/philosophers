/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:03:49 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/08 21:19:58 by rmatsuba         ###   ########.fr       */
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
