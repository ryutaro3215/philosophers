/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:35:33 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/01 19:27:46 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	check_overflow(size_t n, char c)
{
	if (n > INT_MAX / 10)
		return (false);
	if (n == INT_MAX / 10 && c > '7')
		return (false);
	return (true);
}	

bool	check_number(size_t *n, char *argv)
{
	int	i;

	i = 0;
	*n = 0;
	while (argv[i])
	{
		if (argv[0] == '0')
			return (false);
		if (is_number(argv[i]) == false)
			return (false);
		if (check_overflow(*n, argv[i]) == false)
			return (false);
		*n = *n * 10 + argv[i] - '0';
		i++;
	}
	return (true);
}

bool	check_arg(t_arg *arg, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (false);
	if (check_number(&arg->philo_num, argv[1]) == false)
		return (false);
	if (check_number(&arg->die_time, argv[2]) == false)
		return (false);
	if (check_number(&arg->eat_time, argv[3]) == false)
		return (false);
	if (check_number(&arg->sleep_time, argv[4]) == false)
		return (false);
	if (argc == 6 && check_number(&arg->must_eat_count, argv[5]) == false)
		return (false);
	return (true);
}
