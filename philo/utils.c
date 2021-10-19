/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:12:25 by jkasongo          #+#    #+#             */
/*   Updated: 2021/10/19 05:52:02 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace_local(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	nbr;
	int		sign;
	int		i;

	i = 0;
	nbr = 0;
	sign = 1;
	if (!str)
		return (0);
	while (str[i] != 0 && ft_isspace_local(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != 0 && (((int)str[i] >= 48 && (int)str[i] <= 57)))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (sign == -1)
		return ((int)(nbr * -1));
	return ((int)nbr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
		temp[i++] = 0;
	s = temp;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*heap_p;
	size_t	total_size;

	total_size = count * size;
	heap_p = malloc(total_size);
	if (heap_p == NULL)
		return (NULL);
	ft_bzero(heap_p, total_size);
	return (heap_p);
}

size_t	ft_time(void)
{
	struct timeval c_time;

	gettimeofday(&c_time, NULL);
	return ((c_time.tv_sec * 1000) + (c_time.tv_usec / 1000));
}
