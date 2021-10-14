/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:12:25 by jkasongo          #+#    #+#             */
/*   Updated: 2021/10/14 16:30:19 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace_local(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	nbr;
	int		sign;
	int		i;

	i = 0;
	nbr = 0;
	sign = 1;
	if (!str)
		return (0);
	while (str[i] != 0 && ft_isspace_local(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != 0 && (((int)str[i] >= 48 && (int)str[i] <= 57)))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (sign == -1)
		return ((int)(nbr * -1));
	return ((int)nbr);
}

unsigned int	get_number_from_str(const char *str)
{
	unsigned int	number;
	int				nbr;

	number = 0;
	nbr = ft_atoi(str);
	if (nbr > 0)
		number = (unsigned int)nbr;
	return (number);
}

void	ft_print_usage_error(void)
{
	write(STDERR_FILENO, "./philo number_of_philosophers ", 32);
	write(STDERR_FILENO, "time_to_die time_to_eat time_to_sleep ", 39);
	write(STDERR_FILENO, "[number_of_times_each_philosopher_must_eat]\n", 45);
}
