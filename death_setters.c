/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iustoglu <iustoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:14:37 by iustoglu          #+#    #+#             */
/*   Updated: 2022/11/30 14:39:11 by iustoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_meals(t_philo *ph)
{
	pthread_mutex_lock(&ph->args->check_lock);
	ph->last_meal = get_time();
	pthread_mutex_unlock(&ph->args->check_lock);
}

void	set_nb(t_philo *ph)
{
	pthread_mutex_lock(&ph->args->nb_lock);
	++ph->nb_eat;
	pthread_mutex_unlock(&ph->args->nb_lock);
}

void	set_death(t_philo *ph)
{
	pthread_mutex_lock(&ph->args->death_lock);
	ph->args->stop_sim = 1;
	pthread_mutex_unlock(&ph->args->death_lock);
}
