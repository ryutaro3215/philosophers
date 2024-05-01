/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:18:21 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/05/01 19:52:41 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_arg
{
	size_t			philo_num;
	size_t			die_time;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			must_eat_count;
}			t_arg;

typedef struct s_env
{
	pthread_mutex_t *forks;
	size_t			fork_num;
}		t_env;


/* parse argument*/

bool	is_number(char c);
bool	check_overflow(size_t n, char c);
bool	check_number(size_t *n, char *argv);
bool	check_arg(t_arg *arg, int argc, char **argv);

# endif
