/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:58:40 by jkasongo          #+#    #+#             */
/*   Updated: 2021/10/14 16:23:48 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc == 5 || argc == 6)
	{
		return (0);
	}
	else
	{
		ft_print_usage_error();
		return (1);
	}
}
