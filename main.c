/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:50:04 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/19 14:32:14 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_env	env;
	t_philo	*philo;

	if (!check_arg(&info, argc, argv) || !init_env(&env, &info))
	{
		printf("Error\n");
		return (1);
	}
	philo = init_philo(&info, &env);
	if (!philo)
		destroy_forks(info.philo_num, &env);
	philo_threads(philo, &info);
	free_all(info.philo_num, philo);
	printf("finish");
}
