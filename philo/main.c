/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:58:40 by jkasongo          #+#    #+#             */
/*   Updated: 2021/10/18 02:47:54 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	run_threads(t_agora *app)
{
	t_philo	*table;
	size_t	i;
	size_t	start_time;

	table = app->table;
	i = 0;
	start_time = ft_time();
	while (i < app->philo_nbr)
	{
		table[i].life = start_time;
		pthread_create(&table[i].thread_id, NULL, genesis, (void *)&table[i]);
		i += 2;
	}
	i = 1;
	usleep(app->tt_eat - 1);
	while (i < app->philo_nbr)
	{
		table[i].life = start_time;
		pthread_create(&table[i].thread_id, NULL, genesis, (void *)&table[i]);
		i += 2;
	}
	return (true);
}

bool	agora_run(t_agora *app)
{
	size_t	i;
	t_philo	*table;

	app->table = (t_philo *)ft_calloc(app->philo_nbr, sizeof(t_philo));
	if (!app->table)
		return (false);
	table = app->table;
	app->sync = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(app->sync, NULL);
	init_philosphers_data(app);
	run_threads(app);
	i = 0;
	while (i < app->philo_nbr)
	{
		pthread_join(table[i].thread_id, NULL);
		i++;
	}
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
