/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:22:34 by jkasongo          #+#    #+#             */
/*   Updated: 2021/10/19 06:39:11 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	eat(t_philo *diogene);
bool	ft_sleep(t_philo *nietzsche);
bool	think(t_philo *descartes);

void	ft_usleep(size_t	time_in_ms)
{
	size_t	start_time;

	start_time = 0;
	start_time = ft_time();
	while ((ft_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
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
