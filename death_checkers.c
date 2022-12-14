/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iustoglu <iustoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:14:21 by iustoglu          #+#    #+#             */
/*   Updated: 2022/11/30 14:39:02 by iustoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	check_meals(t_philo *ph)
{
	size_t	i;

	pthread_mutex_lock(&ph->args->check_lock);
	i = ph->last_meal;
	pthread_mutex_unlock(&ph->args->check_lock);
	return (i);
}

int	check_nb(t_philo *ph)
{
	int	i;

	pthread_mutex_lock(&ph->args->nb_lock);
	i = ph->nb_eat;
	pthread_mutex_unlock(&ph->args->nb_lock);
	return (i);
}

int	check_death(t_philo *ph)
{
	int	i;

	pthread_mutex_lock(&ph->args->death_lock);
	i = ph->args->stop_sim;
	pthread_mutex_unlock(&ph->args->death_lock);
	return (i);
}
