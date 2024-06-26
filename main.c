/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:50:04 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/22 18:31:02 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q philo");
// }

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
