/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:22:34 by jkasongo          #+#    #+#             */
/*   Updated: 2021/10/18 02:46:26 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	eat(t_philo *diogene)
{
	bool	state;

	state = false;
	pthread_mutex_lock(diogene->own_fork);
	pthread_mutex_lock(diogene->nubble_fork);
	diogene->state = eating;
	if (diogene->nbr_eat > diogene->nbr_eat_max)
		diogene->state = bulimia;
	diogene->nbr_eat++;
	state = sync_code(diogene);
	if (!state)
		return (state);
	usleep(diogene->tt_eat);
	diogene->tw_eating = ft_time();
	return (state);
}

bool	ft_sleep(t_philo *nietzsche)
{
	bool	state;

	state = false;
	nietzsche->state = sleeping;
	state = sync_code(nietzsche);
	pthread_mutex_unlock(nietzsche->nubble_fork);
	pthread_mutex_unlock(nietzsche->own_fork);
	if (!state)
		return (state);
	usleep(nietzsche->tt_sleep);
	return (state);
}

bool	think(t_philo *descartes)
{
	descartes->state = thinking;
	return (sync_code(descartes));
}

void	apocalypse(t_philo *jean)
{
	pthread_mutex_unlock(jean->nubble_fork);
	pthread_mutex_unlock(jean->own_fork);
}

void	*genesis(void *philosopher)
{
	t_philo	*aristote;

	aristote = (t_philo *)philosopher;
	while (1)
	{
		if (!eat(aristote))
		{
			apocalypse(aristote);
			break ;
		}
		if (!ft_sleep(aristote))
			break ;
		if (!think(aristote))
			break ;
	}
	return (philosopher);
}
