/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:35:33 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/01 15:09:42 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	check_number(char *argv)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (argv[i])
	{
		if (is_number(argv[i] == false))
			return (false);
		num = num * 10 + (argv[i] - '0');
		if (num > INT_MAX )
		i++;
	}
	return (true);
}

bool	check_arg(int argc, char **argv)
{
	if (argc != 4 && argc != 5)
		return (false);
	if (check_number(argv[1]) == false)
		return (false);
	if (check_number(argv[2]) == false)
		return (false);
	if (check_number(argv[3]) == false)
		return (false);
	if (argc == 5 && check_number(argv[4]) == false)
		return (false);
	return (true);
}
