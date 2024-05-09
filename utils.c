/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:32:46 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/05/09 19:34:18 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) == -1)
		return (1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}