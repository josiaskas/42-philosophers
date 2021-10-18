/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:55:37 by jkasongo          #+#    #+#             */
/*   Updated: 2021/10/18 01:46:31 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

enum e_state
{
	waiting_fork,
	take_fork,
	eating,
	sleeping,
	thinking,
	died,
	bulimia,
};

typedef struct s_philospher
{
	size_t			number;
	pthread_t		thread_id;
	pthread_mutex_t	*own_fork;
	pthread_mutex_t	*nubble_fork;
	pthread_mutex_t	*sync;
	size_t			tt_die;
	size_t			tt_eat;
	size_t			tt_sleep;
	size_t			tw_eating;
	size_t			life;
	size_t			nbr_eat;
	size_t			nbr_eat_max;
	enum e_state	state;
}	t_philo;

typedef struct s_agora
{
	t_philo			*table;
	size_t			philo_nbr;
	size_t			tt_die;
	size_t			tt_eat;
	size_t			tt_sleep;
	size_t			max_eat_nbr;
	pthread_mutex_t	*sync;
}	t_agora;

void	init_philosphers_data(t_agora *app);
void	*genesis(void *philosopher);
bool	sync_code(t_philo *kant);

size_t	get_number_from_str(const char *str);
void	ft_print_usage_error(void);
bool	ft_parse_args(int argc, char *argv[], t_agora *app);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_time(void);
#endif
