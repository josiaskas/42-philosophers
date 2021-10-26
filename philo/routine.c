/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:22:34 by jkasongo          #+#    #+#             */
/*   Updated: 2021/10/26 00:15:05 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	eat(t_philo *diogene);
bool	ft_sleep(t_philo *nietzsche);
bool	think(t_philo *descartes);

void	*last_day(void *philosopher)
{
	t_philo	*confucius;
	size_t	jesus_ac;

	confucius = (t_philo *)philosopher;
	jesus_ac = ft_time() - confucius->life;
	pthread_mutex_lock(confucius->own_fork->mutex);
	printf("%ld 1 has taken a fork\n", jesus_ac);
	confucius->own_fork->fork = true;
	pthread_mutex_unlock(confucius->own_fork->mutex);
	ft_usleep(confucius->tt_die);
	jesus_ac = ft_time() - confucius->life;
	printf("%ld 1 died\n", jesus_ac);
	return (philosopher);
}

void	*genesis(void *philosopher)
{
	t_philo	*aristote;

	aristote = (t_philo *)philosopher;
	aristote->last_eat = ft_time();
	while (1)
	{
		if (!eat(aristote))
		{
			aristote->own_fork->fork = false;
			pthread_mutex_unlock(aristote->nubble_fork->mutex);
			pthread_mutex_unlock(aristote->own_fork->mutex);
			break ;
		}
		if (!ft_sleep(aristote))
			break ;
		if (!think(aristote))
			break ;
	}
	return (philosopher);
}

bool	eat(t_philo *diogene)
{
	pthread_mutex_lock(diogene->own_fork->mutex);
	pthread_mutex_lock(diogene->nubble_fork->mutex);
	diogene->own_fork->fork = true;
	diogene->state = eating;
	if (diogene->nbr_eat > diogene->nbr_eat_max)
	{
		diogene->state = bulimia;
		return (false);
	}
	diogene->nbr_eat++;
	if (!sync_code(diogene))
		return (false);
	diogene->last_eat = ft_time();
	ft_usleep(diogene->tt_eat);
	diogene->own_fork->fork = false;
	pthread_mutex_unlock(diogene->nubble_fork->mutex);
	pthread_mutex_unlock(diogene->own_fork->mutex);
	return (true);
}

bool	ft_sleep(t_philo *nietzsche)
{
	nietzsche->state = sleeping;
	if ((ft_time() - (nietzsche->last_eat)) >= nietzsche->tt_die)
		nietzsche->state = died;
	if (!sync_code(nietzsche))
		return (false);
	if (((ft_time() + nietzsche->tt_sleep) - (nietzsche->last_eat))
		>= nietzsche->tt_die)
	{
		usleep(1);
		nietzsche->state = died;
		return (sync_code(nietzsche));
	}
	ft_usleep(nietzsche->tt_sleep);
	return (true);
}

bool	think(t_philo *descartes)
{
	descartes->state = thinking;
	if ((ft_time() - descartes->last_eat) > descartes->tt_die)
		descartes->state = died;
	return (sync_code(descartes));
}
