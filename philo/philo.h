/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:55:37 by jkasongo          #+#    #+#             */
/*   Updated: 2021/10/14 15:35:56 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

enum e_state
{
	eating,
	sleeping,
	thinking,
};

typedef struct s_philosphers
{
	int				number;
	int				time_to_die;
	int				number_of_time;
	enum e_state	state;
}	t_philo;

unsigned int	get_number_from_str(const char *str);
void			ft_print_usage_error(void);
#endif