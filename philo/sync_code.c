/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:35:56 by jkasongo          #+#    #+#             */
/*   Updated: 2021/11/12 01:17:31 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_died_waiting(t_philo *hugo)
{
	static bool	stopped = 0;

	if (stopped >= 1)
		return (false);
	if ((long long)(hugo->tt_die - (ft_time() - hugo->last_eat))
		< (long long)hugo->tt_eat)
	{
		hugo->state = died;
		ft_usleep((hugo->tt_die - (ft_time() - hugo->last_eat)));
		sync_code(hugo);
		stopped++;
		return (false);
	}
	return (true);
}

void	ft_usleep(size_t time_in_ms)
{
	size_t	start_time;

	start_time = 0;
	start_time = ft_time();
	while ((ft_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

static bool	ft_printer(t_philo	*rousseau)
{
	size_t	jesus_ac;
	size_t	chronos;

	jesus_ac = ft_time() - rousseau->life;
	chronos = ft_time() - rousseau->last_eat;
	if (chronos > rousseau->tt_die)
		return (false);
	else if (rousseau->state == eating)
	{
		printf("%ld %ld has taken a fork\n", jesus_ac, rousseau->number);
		printf("%ld %ld has taken a fork\n", jesus_ac, rousseau->number);
		printf("%ld %ld is eating\n", jesus_ac, rousseau->number);
	}
	else if (rousseau->state == sleeping)
		printf("%ld %ld is sleeping\n", jesus_ac, rousseau->number);
	else if (rousseau->state == thinking)
		printf("%ld %ld is thinking\n", jesus_ac, rousseau->number);
	return (true);
}

bool	ft_death(t_philo *john)
{
	size_t	jesus_ac;

	jesus_ac = ft_time() - john->life;
	printf("%ld %ld died\n", jesus_ac, john->number);
	return (false);
}

bool	sync_code(t_philo *kant)
{
	static bool		state = true;

	pthread_mutex_lock(kant->sync);
	if (state == false)
		state = false;
	else if (kant->state == died)
	{
		state = false;
		ft_death(kant);
	}
	else
	{
		state = ft_printer(kant);
		if (state == false)
			ft_death(kant);
	}
	pthread_mutex_unlock(kant->sync);
	return (state);
}
