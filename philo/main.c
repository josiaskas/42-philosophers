/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:58:40 by jkasongo          #+#    #+#             */
/*   Updated: 2021/10/17 04:20:55 by jkasongo         ###   ########.fr       */
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
	platon.nbr_eat_max = app->max_eat_nbr;
	platon.state = waiting_fork;
	platon.nbr_eat = 0;
	platon.murder = app->murder;
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

void	init_threads_data(t_agora *app)
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
			table[i] = prepare_philo(i, app, 0, 1);
		else if (i == (app->philo_nbr - 1))
			table[i] = prepare_philo(i, app, table[i - 1].own_fork, 3);
		else
			table[i] = prepare_philo(i, app, table[i - 1].own_fork, 2);
		i++;
	}
}

bool	agora_run(t_agora *app)
{
	t_philo	*table;
	size_t	i;

	i = 0;
	app->table = (t_philo *)ft_calloc(app->philo_nbr, sizeof(t_philo));
	if (!app->table)
		return (false);
	app->murder = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(app->murder, NULL);
	pthread_mutex_lock (app->murder);
	init_threads_data(app);
	table = app->table;
	while (i < app->philo_nbr)
	{
		pthread_create(&table[i].thread_id, NULL, genesis, (void *)&table[i]);
		i++;
	}
	pthread_mutex_unlock(app->murder);
	pthread_mutex_destroy(app->murder);
	return (true);
}

int	main(int argc, char *argv[])
{
	t_agora	app;

	app.table = NULL;
	app.max_eat_nbr = 2147483647;
	if (argc == 5 || argc == 6)
	{
		if (!ft_parse_args(argc, argv, &app))
			return (1);
		else
			agora_run(&app);
		return (0);
	}
	else
	{
		ft_print_usage_error();
		return (1);
	}
}
