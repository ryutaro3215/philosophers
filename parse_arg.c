/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:10:56 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/16 18:25:30 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

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
			return (printf("Invalid argument\n"), false);
		if (is_number(argv[i]) == false)
			return (printf("It's not number\n"), false);
		if (check_overflow(*n, argv[i]) == false)
			return (printf("overflow\n"), false);
		*n = *n * 10 + argv[i] - '0';
		i++;
	}
	return (true);
}

bool	check_arg(t_info *info, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (false);
	if (check_number(&info->philo_num, argv[1]) == false)
		return (false);
	if (check_number(&info->tt_die, argv[2]) == false)
		return (false);
	if (check_number(&info->tt_eat, argv[3]) == false)
		return (false);
	if (check_number(&info->tt_sleep, argv[4]) == false)
		return (false);
	if (argc == 5)
	{
		info->must_eat_count = 0;
		info->must_eat = false;
	}
	if (argc == 6)
	{
		info->must_eat = true;
		if (check_number(&info->must_eat_count, argv[5]) == false)
			return (false);
	}
	return (true);
}
