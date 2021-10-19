/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:15:00 by jkasongo          #+#    #+#             */
/*   Updated: 2021/10/19 06:22:49 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	prepare_philo(size_t n, t_agora *app, t_fork *nubble)
{
	t_philo			platon;

	platon.number = n + 1;
	platon.tt_die = app->tt_die;
	platon.tt_eat = app->tt_eat;
	platon.tt_sleep = app->tt_sleep;
	platon.last_eat = 0;
	platon.life = 0;
	platon.nbr_eat_max = app->max_eat_nbr;
	platon.nbr_eat = 0;
	platon.sync = app->sync;
	platon.own_fork = &app->couverts[n];
	platon.nubble_fork = nubble;
	return (platon);
}

void	init_forks(t_fork *couverts, size_t n)
{
	pthread_mutex_t	*own;
	size_t			i;

	i = 0;
	while (i < n)
	{
		own = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
		couverts[i].mutex = own;
		couverts[i].fork = false;
		pthread_mutex_init(couverts[i].mutex, NULL);
		i++;
	}
}

void	init_philosphers_data(t_agora *app)
{
	t_philo			*table;
	t_fork			*couverts;
	size_t			i;

	i = 0;
	table = app->table;
	couverts = app->couverts;
	init_forks(app->couverts, app->philo_nbr);
	while (i < app->philo_nbr)
	{
		if (i == 0)
			table[i] = prepare_philo(i, app, &couverts[app->philo_nbr - 1]);
		else
			table[i] = prepare_philo(i, app, &couverts[i - 1]);
		i++;
	}
}

void	clean_table(t_agora *app)
{
	size_t	i;

	i = 0;
	while (i < app->philo_nbr)
	{
		pthread_mutex_destroy(app->couverts[i].mutex);
		free(app->couverts[i].mutex);
		i++;
	}
	free(app->couverts);
	pthread_mutex_destroy(app->sync);
	free(app->sync);
	free(app->table);
}
