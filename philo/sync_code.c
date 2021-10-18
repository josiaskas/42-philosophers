/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:35:56 by jkasongo          #+#    #+#             */
/*   Updated: 2021/10/18 02:43:45 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_printer(t_philo	*rousseau)
{
	size_t	time;
	size_t	without_eating;

	time = ft_time() - rousseau->life;
	without_eating = ft_time() - rousseau->tw_eating;
	if (rousseau->state == eating)
	{
		printf("%ld %ld has taken a fork\n", time, rousseau->number);
		printf("%ld %ld has taken a fork\n", time, rousseau->number);
		printf("%ld %ld is eating 🍝\n", time, rousseau->number);
		rousseau->nbr_eat++;
	}
	else if (rousseau->state == sleeping)
	{
		if (without_eating >= rousseau->tt_die)
			return (false);
		printf("%ld %ld is sleeping 🛌\n", time, rousseau->number);
	}
	else if (rousseau->state == thinking)
	{
		if (without_eating >= rousseau->tt_die)
			return (false);
		printf("%ld %ld is thinking 💭\n", time, rousseau->number);
	}
	return (true);
}

bool	sync_code(t_philo *kant)
{
	static bool	murder = false;
	bool		state;
	size_t		time;

	pthread_mutex_lock(kant->sync);
	time = ft_time() - kant->life;
	state = false;
	if ((murder == true) || (kant->state == bulimia))
		state = false;
	else if (kant->state == died)
	{
		printf("%ld %ld died  1 💀\n", time, kant->number);
		murder = true;
		state = false;
	}
	else
	{
		state = ft_printer(kant);
		if (state == false)
		{
			kant->state = died;
			printf("%ld %ld died 2 💀\n", time, kant->number);
			murder = true;
			state = false;
		}
	}
	pthread_mutex_unlock(kant->sync);
	return (state);
}
