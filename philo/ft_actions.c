/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <georgerobert147@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:32:59 by grobert           #+#    #+#             */
/*   Updated: 2023/05/26 10:30:49 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_dead(t_philo *philo)
{
	if (ft_get_time(philo->tv) - philo->time >= philo->data->time_to_die)
	{
		philo->run = 0;
		philo->data->run = 0;
		printf("%d %d %s\n", ft_get_time(philo->tv) - philo->data->start_time,
			philo->id, "died");
		return (0);
	}
	else if (!(philo->eat))
	{
		philo->run = 0;
		return (0);
	}
	return (1);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->philos[philo->prev_id].fork);
	ft_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->fork);
	ft_print(philo, "has taken a fork");
	ft_print(philo, "is eating");
	philo->time = ft_get_time(philo->tv);
	philo->eat -= (philo->eat != -1);
	ft_usleep(philo, philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->data->philos[philo->prev_id].fork);
}

int	ft_check_input(int ac, char **av)
{
	int		i;

	if (ac < 5)
		return (printf("Error\nType: not enough arguments\n") * 0);
	if (ac > 6)
		return (printf("Error\nType: too much arguments\n") * 0);
	while (--ac > 0)
	{
		i = -1;
		while (av[ac][++i])
		{
			if (av[ac][i] > 57 || av[ac][i] < 48)
				return (printf("Error\nType: invalid input\n") * 0);
		}
	}
	return (1);
}
