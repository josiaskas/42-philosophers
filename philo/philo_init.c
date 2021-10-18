/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:15:00 by jkasongo          #+#    #+#             */
/*   Updated: 2021/10/18 01:26:58 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	prepare_philo(size_t n, t_agora *app, pthread_mutex_t *nubble, int i)
{
	t_philo			platon;
	pthread_mutex_t	*own;

	platon.number = n;
	platon.tt_die = app->tt_die;
	platon.tt_eat = app->tt_eat;
	platon.tt_sleep = app->tt_sleep;
	platon.tw_eating = 0;
	platon.life = 0;
	platon.nbr_eat_max = app->max_eat_nbr;
	platon.nbr_eat = 0;
	platon.sync = app->sync;
	if (i != 1)
		platon.nubble_fork = nubble;
	else
		platon.nubble_fork = app->table[app->philo_nbr - 1].own_fork;
	if (i != 3)
	{
		own = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
		platon.own_fork = own;
		pthread_mutex_init(platon.own_fork, NULL);
	}
	else
		platon.own_fork = app->table[0].nubble_fork;
	return (platon);
}

void	init_philosphers_data(t_agora *app)
{
	t_philo			*table;
	pthread_mutex_t	*last_fork;
	size_t			i;

	i = 0;
	last_fork = NULL;
	table = app->table;
	last_fork = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	table[app->philo_nbr - 1].own_fork = last_fork;
	pthread_mutex_init(last_fork, NULL);
	while (i < app->philo_nbr)
	{
		if (i == 0)
			table[i] = prepare_philo(i + 1, app, 0, 1);
		else if (i == (app->philo_nbr - 1))
			table[i] = prepare_philo(i + 1, app, table[i - 1].own_fork, 3);
		else
			table[i] = prepare_philo(i + 1, app, table[i - 1].own_fork, 2);
		i++;
	}
}

size_t	ft_time(void)
{
	struct timeval	c_time;

	gettimeofday(&c_time, NULL);
	return ((c_time.tv_sec * 1000) + (c_time.tv_usec / 1000));
}
