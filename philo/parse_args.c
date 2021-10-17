/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:26:32 by jkasongo          #+#    #+#             */
/*   Updated: 2021/10/17 02:02:56 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_parse_args(int argc, char *argv[], t_agora *app)
{
	app->philo_nbr = get_number_from_str(argv[1]);
	app->tt_die = get_number_from_str(argv[2]);
	app->tt_eat = get_number_from_str(argv[3]);
	app->tt_sleep = get_number_from_str(argv[4]);
	if (argc == 6)
		app->max_eat_nbr = get_number_from_str(argv[5]);
	if ((!app->philo_nbr) || (!app->tt_die) || (!app->tt_eat)
		|| (!app->tt_sleep || (!app->max_eat_nbr)))
	{
		write(STDERR_FILENO, "philo: args Error\n", 19);
		return (false);
	}
	return (true);
}

void	ft_print_usage_error(void)
{
	write(STDERR_FILENO, "./philo number_of_philosophers ", 32);
	write(STDERR_FILENO, "time_to_die time_to_eat time_to_sleep ", 39);
	write(STDERR_FILENO, "[number_of_times_each_philosopher_must_eat]\n", 45);
}
