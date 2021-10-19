/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:26:32 by jkasongo          #+#    #+#             */
/*   Updated: 2021/10/19 06:08:45 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_all_numeric(const char *str, size_t max_chars)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < '0' || str[i] > '9' || i > max_chars)
			return (false);
		i++;
	}
	return (true);
}

size_t	get_number_from_str(const char *str, size_t max_nbr)
{
	size_t	number;
	int		nbr;

	number = 0;
	if (!ft_all_numeric(str, 10))
		return (0);
	nbr = ft_atoi(str);
	if ((nbr > 0) && (nbr <= 2147483647))
		number = (size_t)nbr;
	if (number > max_nbr)
		return (0);
	return (number);
}

bool	ft_parse_args(int argc, char *argv[], t_agora *app)
{
	app->philo_nbr = get_number_from_str(argv[1], 2147483647);
	app->tt_die = get_number_from_str(argv[2], 2147483647);
	app->tt_eat = get_number_from_str(argv[3], 2147483647);
	app->tt_sleep = get_number_from_str(argv[4], 2147483647);
	if (argc == 6)
		app->max_eat_nbr = get_number_from_str(argv[5], 2147483647);
	if ((!app->philo_nbr) || (!app->tt_die) || (!app->tt_eat)
		|| (!app->tt_sleep || (!app->max_eat_nbr)))
	{
		write(STDERR_FILENO, "Philo: args error\n", 19);
		return (false);
	}
	return (true);
}

void	ft_print_usage_error(void)
{
	write(2, "Usage: ./philo", 15);
	write(2, "\033[0;32m number_of_philosophers\033[0;39m", 38);
	write(2, "\033[0;33m time_to_die\033[0;39m", 27);
	write(2, "\033[0;34m time_to_eat\033[0;39m", 27);
	write(2, "\033[0;34m time_to_sleep\033[0;39m", 29);
	write(2, " [number_of_times_each_philosopher_must_eat]\n", 46);
}
