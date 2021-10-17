/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:22:34 by jkasongo          #+#    #+#             */
/*   Updated: 2021/10/17 04:23:00 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*genesis(void *philosopher)
{
	t_philo	*aristote;

	aristote = (t_philo *)philosopher;
	printf("%ld start --> Gauche: %p Droite: %p\n", aristote->number, aristote->nubble_fork, aristote->own_fork);
	pthread_mutex_lock(aristote->murder);
	printf("murder open\n");
	pthread_mutex_unlock(aristote->murder);
	return (NULL);
}
