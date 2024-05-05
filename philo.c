/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:03:49 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/03 23:30:14 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg	arg;
	t_env	env;
	t_mutex	*mutex;
	t_philo	*philo;

	if (!check_arg(&arg, argc, argv) || !init_fork(arg, &env))
		printf("Error\n");
	mutex = init_mutex(&env);
	philo = init_philo(&arg, &env, mutex);
	if (philo == NULL)
		printf("Error\n");

	return (0);
}
